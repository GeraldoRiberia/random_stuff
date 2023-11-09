#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node node_;

void printList(node_ *head){
    node_ *temp = head;
    while(temp != NULL){
        printf("%d - ", temp->data);
        temp = temp->next;
    }
}

node_ *createNode(int value){
    node_ *res = malloc(sizeof(node_));
    res->data=value;
    res->next=NULL;
    return res;
} 
int main(){
    node_ *tmp;
    node_ *head=NULL;

    for(int i =0; i<12;i++){
        tmp = createNode(i);
        tmp->next=head;
        head = tmp;
    }
    
    printList(head);
    printf("\n");
}