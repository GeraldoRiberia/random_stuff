#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*start=NULL,*last=NULL;

typedef struct node node_;
void duplicate(){
    node_ *cur=start, *nxt=NULL,*prev;
    while(cur != NULL && cur->next != NULL){
        nxt = cur->next;
        prev = cur;
        while(nxt != NULL){
            if(cur->data == nxt->data){
                node_* temp = nxt;
                prev->next = nxt->next;
                free(temp);
            }
            else{
                prev = nxt;
                nxt = nxt->next;
            }
        }
        cur = cur->next;
    }
}
void input(){
    node_* ptr = (node_*)malloc(sizeof(node_));
    printf("Enter value"); 
    scanf("%d",&ptr->data);
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
        node_ *temp = start;
        while(temp != NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}
void main(){
    while(1){
        printf("Enter 1 to input 2 to duplicate 3 to print");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1 : input();break;
            case 2 : duplicate(); break;
            case 3 : print(); break;
            default : break;
        }
    }
}