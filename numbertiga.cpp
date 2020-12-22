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
void printfmiddleonly(Node *A){
    Node*s=A, *p=A;
    if(A){
        while(p!=NULL && p->next!=NULL){
            s=s->next;
            p=p->next->next;
        }
        printf("%d\n",s->data);
    }
}

int main(){
    Node *A =NULL;
    //linked list is 1->2->3;; middle is 2;
    pushHead(&A,1);
    pushHead(&A,2);
    pushHead(&A,3);
    printfmiddleonly(A);
    return 0;
}