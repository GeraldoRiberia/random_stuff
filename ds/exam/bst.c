#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the binary search tree
struct Node* insert(struct Node* root, int key) {
    // Base case: If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(key);
    }

    // Otherwise, recur down the tree
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    // Return the unchanged node pointer
    return root;
}

// Function to perform in-order traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d  ",root->key);
    inorderTraversal(root->right);
}

void preorder(struct Node* root){
    if(root == NULL)
        return;
    printf("%d  ",root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->key);
}

struct Node* deletion(struct Node* root, int key){
    struct Node *t=root, *prev=NULL;
    //finding key in bst
    while(t!= NULL && t->key != key){
        if(t->key > key){
            prev = t;
            t = t->left;
        }
        else{
            prev =t;
            t= t->right;
        }
    }
    //if key not found t will be null
    if(t == NULL){
        printf("Key not found");
        return root;
    }
    //case 1 : no child
    if(t->left == NULL && t->right == NULL){
        if(prev->left == t ){
            prev->left = NULL;
            free(t);
        }
        else{
            prev->right = NULL;
            free(t);
        }
    }
    //case 2 : one child 
    else if(t->left == NULL && t->right != NULL){
        if(prev->left == t){
            prev->left = t->right;
            free(t);
        }
        else{
            prev->right = t->right;
            free(t);
        }
    }
    //case 2 : one child
    else if(t->right == NULL && t->left != NULL){
        if(prev->left == t){
            prev->left = t->left;
            free(t);
        }
        else{
            prev->right = t->left;
            free(t);
        }
    }
    //case 3 : find inordersuccessor and swap with key(t) and free inordersuccessor
    else{
        struct Node *successor=t->right,*successorParent=t;

        while(successor->left != NULL){
            successorParent = successor;
            successor = successor->left;
        }
        t->key = successor->key;
        if(successor == successorParent->left){
            successorParent->left = NULL;
        }
        else{
            successorParent->right = NULL;
        }
        free(successor);
    }
    return root;
}

// Main function to test the binary search tree implementation
int main() {
    struct Node* root = NULL;
    int key,ch;
    while(1){
    printf("Enter choice\n1.Input\n2.Inorder\n3.Preorder\n4.Postorder");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("Enter value : ");
        int val;
        scanf("%d",&val);
        root = insert(root,val);
        break;
    case 2 :
        inorderTraversal(root);
        break;
    case 3 : 
        preorder(root);
        break;
    case 4 :
        postorder(root);
        break;
    case 5 : 
        printf("Enter key to delete");
        scanf("%d",&key);
        root = deletion(root,key);
        break;
    
    default:
        break;
    }
    }
    return 0;
}
