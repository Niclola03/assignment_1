#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void pushHead(Node **nodes,int score){
   struct Node* temp= new Node;
    temp -> data= score;
    temp -> next = *nodes;
    *nodes = temp;
}
void printsreverse(Node *any){
  if(any==NULL)return;
  printsreverse(any->next);
  printf("%d",any->data);
}
int main(){
    Node *A =NULL;
    pushHead(&A,8);
    pushHead(&A,7);
    pushHead(&A,6);
    pushHead(&A,5);
    pushHead(&A,4);
    pushHead(&A,3);
    pushHead(&A,2);
    pushHead(&A,1);
    //1->2->3->4
    //Output should be 4->3->2->1;
    printsreverse(A);
    printf("\n");
    return 0;
}