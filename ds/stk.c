#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL,*ptr;

typedef struct node node_;

void push(){
    ptr=(node_*)malloc(sizeof(node_));
    printf("Enter value : ");
    scanf("%d",&ptr->data);
    if(top == NULL){
        top = ptr;
    }
    else{
        ptr->next = top;
        top = ptr;
    }
}

void pop(){
    if(top == NULL){
        printf("Stack underflow\n");
    }
    else if( top->next == NULL){
        printf("Popped element : %d\n",top->data);
        free(top);
        top = NULL;
    }
    else{
        node_ *t = top;
        printf("Popped element : %d\n",top->data);
        top = top->next;
        free(t);
    }
}
void display(){
    if(top == NULL){
        printf("Stack Underflow\n");
    }
    else{
        node_ *t= top;
        printf("Stack Elements are : ");
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t=t->next;
        }
        printf("\n");
    }
}
int isEmpty(){
    if(top == NULL){
        printf("Stack Empty\n");
    }
    else{
        printf("Stack not empty\n");
    }
}

void main(){
    int ch;
    while(1){
        printf("1.Push\n2.Pop\n3.Check If Stack is Empty\n4.Display\n0.Exit\nEnter your choice :");
        scanf("%d",&ch);
        if(ch == 0){break;}
        switch(ch){
            case 1 : push();
                    break;
            case 2 : pop();
                    break;
            case 3 :isEmpty();
                    break;
            case 4 : display();
                    break;
            default : printf("Invalid choice\n");
        }
    }
}