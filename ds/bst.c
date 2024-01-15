#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node node_;

node_* create_node(int val){
    node_* ptr = (node_*)malloc(sizeof(node_));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right= NULL;
    return ptr;
}

node_* insert(node_* root){
    int val;
    printf("Enter value : ");
    scanf("%d",&val);
    node_ *ptr = create_node(val);
    if(root == NULL){
        return ptr;
    }
    else{
        node_* prev = NULL,*t = root;
        if(ptr->data > t->data){
            prev = t;
            t= t->right;
        }
        else if(ptr->data < t->data){
            prev = t;
            t = t->left;
            
        }
        if(prev->data > ptr->data){
            prev->left = ptr;
        }
        else{
            prev->right = ptr;
        }
    }
    return root;
}

void inorder(struct node* node)
{
    if (node == NULL)
        return;
 
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(node_* nd){
    if(nd == NULL)
        return;
    printf("%d",nd->data);
    preorder(nd->left);
    preorder(nd->right);
}

void postorder(node_* nd){
    if(nd == NULL)
        return;
    postorder(nd->left);
    postorder(nd->right);
    printf("%d",nd->data);
}

void main(){
    node_* root=NULL;
    int val;
    int ch;
    while(1){
    printf("Enter choice\n 1. Input\n2.Inorder\n3.Preorder\n4.Postorder");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        root = insert(root);
        break;
    case 2 :
        inorder(root);
        break;
    case 3 : 
        preorder(root);
        break;
    case 4 :
        postorder(root);
        break;
    
    default:
        break;
    }
    }
}