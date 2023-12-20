#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*start,*last;

typedef struct node* node_;

void reverse(){
    if(start == NULL){
        printf("List empty");
    }
    else{
        node_ prev = NULL,nxt,cur=start;
        while(cur != NULL){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        start = prev;
    }
}

void input(){
    node_ ptr = (node_)malloc(sizeof(node_));
    printf("Enter value"); 
    scanf("%d",&ptr->data);
    ptr->next = NULL;
    if(start == NULL){
        start = ptr;
        last = ptr;
    }
    else{
        last->next = ptr;
        last = ptr;
    }
}
void print(){
    if(start == NULL){
        printf("List empty");
    }
    else{
        node_ temp = start;
        while(temp != NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}
void main(){
    while(1){
        printf("Enter 1 to input 2 to reverse 3 to print");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1 : input();break;
            case 2 : reverse(); break;
            case 3 : print(); break;
            default : break;
        }
    }
}