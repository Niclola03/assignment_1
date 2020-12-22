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
void removeduplicates(Node *A){
    Node *C=A;
    Node *N;
    if(C==NULL)return;
    while(C->next){
        if(C->data == C->next->data){
            N=C->next->next;
            free(C->next);
            C->next=N;
        }
        else C=C->next;
    }
}
void prints(Node *any){
   while(any){
       printf("%d ",any->data);
       any=any->next;
   } 
}
int main(){
    Node *A =NULL;
    pushHead(&A,4);
    pushHead(&A,4);
    pushHead(&A,3);
    pushHead(&A,2);
    pushHead(&A,1);
    pushHead(&A,1);
    removeduplicates(A);
    prints(A);
    return 0;
}