#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node node_;
node_* createNode(int value){
    node_* ptr = malloc(sizeof(node_));
    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

node_* insert(node_* root, int val) {
    node_* newNode = createNode(val);
    
    if (root == NULL)
        return newNode;

    node_* current = root;
    node_* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (val < current->data)
            current = current->left;
        else if (val > current->data)
            current = current->right;
        else
            return root;
    }

    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

void inorder(node_* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
}

node_* delete(node_* root, int key){
    node_* t = root;
    node_* prev = NULL;
    while(t != NULL){
        if(t->data > key){
            prev = t;
            t = t->left;
        }
        else if(t->data < key){
            prev = t;
            t = t->right;
        }
        else{
            break;
        }

    }
    if( t == NULL){
        printf("Key not found");
        return root;
    }
    else{
        if(t->right == NULL){
            if(t->left != NULL){
                prev->right = t->left;
            }
            else{
                if(prev->right == t){
                    prev->right = t->left;
                }
                else{
                    prev->left = t->left;
                }
                free(t);
                return root;
            }
        }
        else if (t->left == NULL){
            if(t->right != NULL){
                prev->right = t->right;
            }
            else{
                if(prev->right == t){
                    prev->right = t->right;
                }
                else{
                    prev->right = t->left;
                }
                free(t);
                return root;
            }
        }
        else{
            node_* sprev = t;
            node_* succ = t->right; 

            while(succ->left != NULL){
                sprev = succ;
                succ = succ->left;
            }
            if(sprev != t){
                sprev->left = succ->right;
            }
            else{
                sprev->right = succ->right;
            }
            
            int temp = t->data;
            t->data = succ->data;
            succ->data = temp;
            free(succ);
            return root;

        }

    }
}

void main(){
    node_* root = NULL;
    int val;
    int ch;
    /*root = createNode(50);
    root->left = createNode(30);
    root->left = createNode(20);
    root->left->right = createNode(40);
    root->right = createNode(60);
    root->right->left = createNode(55);
    root->right->right = createNode(80);
    root->right->right->left = createNode(77);*/
    do{
        printf("Enter value : "); scanf("%d",&val);
        root = insert(root,val);
        printf("enter 0 to exit");
        scanf("%d",&ch);
    }while(ch != 0);


    printf("Before Deletion \n");
    inorder(root);
    printf("\nEnter key : ");
    int key; scanf("%d",&key);
    root = delete(root,key);
    printf("After Deletion \n");
    inorder(root);
}