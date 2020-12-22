#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*head,*tail;
Node *createNode(int score) {
  Node *temp = new Node;
  temp -> data =score;
  temp ->next =NULL;
  return temp;
}

void pushHead(Node **nodes,int score){
    Node *temp= createNode(score);
    temp-> next= *nodes;
    *nodes=temp;
}
void pushTail(int score){
    Node *temp= createNode(score);
    if(!tail){
        head =tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}
void switchAB(Node *NodeA,Node *NodeB){
    Node *tempA=NodeA,*tempB=NodeB;
    while(tempA&&tempB){
        if((tempA->data) < (tempB->data)){
            pushTail(tempA->data);
            tempA=tempA->next;
        }
        else{
            pushTail(tempB->data);
            tempB=tempB->next;
        }
    }
    while(tempA){
        pushTail(tempA->data);
        tempA=tempA->next;

    }
    while(tempB){
        pushTail(tempB->data);
        tempB=tempB->next;
    }
}
void prints(Node *nodes){
    while(nodes){
        if(nodes->next==NULL){
            printf("%d ",nodes->data);
            nodes=nodes->next;
       }
        else{
            printf("%d ",nodes->data);
            nodes =nodes->next;
     }
    }
}
int main(){
    Node *A =NULL;
    Node *B =NULL;
    pushHead(&A,5);
    pushHead(&A,3);
    pushHead(&B,9);
    pushHead(&B,8);
    pushHead(&B,6);
    switchAB(A,B);
    prints(head);
    return 0;
}