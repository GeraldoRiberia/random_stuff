#include<stdio.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
}*ptr,*root =NULL,*t;

typedef struct node node_;

void create(){
    ptr =(node_*) malloc(sizeof(node_));
    printf("Enter item");
    scanf("%d",&ptr->data);
    ptr->left = NULL;
    ptr->right = NULL;
    if(root == NULL){
        root = ptr;
    }
    else{
        t = root;
        while(t!=NULL){
            if(t->data < ptr->data){
                if(t->right == NULL){
                    t->left = ptr;
                }
                else {
                    t = t->left;
                }
            }
            else{
                if(t->left == NULL){
                    t = ptr;
                }
                else{
                    t = t->right;
                }
            }
        }
    }
}