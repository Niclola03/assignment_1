#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
    int warning;
};

void pushHead(Node **nodes,int score){
   struct Node* temp= new Node;
    temp -> data= score;
    temp -> warning=0;
    temp -> next = *nodes;
    *nodes = temp;
}
int detection_function(Node* A){
    Node *tempA=A, *tempA2=A;
    while(tempA && tempA2 && tempA2->next){
        if(tempA==tempA2){
            return 1;
        }
        tempA=tempA->next;
        tempA2=tempA2->next->next;
    }
    return 0;
}

int main(){
    Node *head =NULL;
    pushHead(&head,1);
    pushHead(&head,2);
    pushHead(&head,3);
    head->next->next->next=head;
    if(detection_function(head)){
        printf("Yes\n");
    }
    else printf("No\n");
    return 0;
}