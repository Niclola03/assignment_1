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
void printthe_n(Node* A, int n) 
{ 
    static int i = 0; 
    if (A == NULL)return; 
    printthe_n(A->next, n); 
    if (++i == n)printf("%d", A->data); 
} 
void prints(Node *any){
   while(any){
       printf("%d\n",any->data);
       any=any->next;
   } 
}
int main(){
    Node *A =NULL;
    pushHead(&A,1);
    pushHead(&A,2);
    pushHead(&A,3);
    pushHead(&A,4);
    //N=2 thus from 4->3->2->1
    //            N=4,,3,,2,,1
    //prints 2 which is on node 2;
    printthe_n(A,2);
    //prints(A);
    return 0;
}