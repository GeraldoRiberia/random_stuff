#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node *next;
}*p=NULL,*last1=NULL,*q=NULL,*last2=NULL,*r=NULL,*last3=NULL,*r1 = NULL, *last4 = NULL;

typedef struct node* node_;

node_ create_node(int coef, int exp){
    node_ ptr = (node_)malloc(sizeof(struct node));
    ptr->coeff= coef;
    ptr->exp= exp;
    ptr->next= NULL;
    return ptr;
}

void input(){
    int exp, coeff,n;
    printf("Input exp 1");
    printf("Enter number of elements");
    scanf("%d",&n);
    while(n>0){
        printf("Enter Exponent");
        scanf("%d",&exp);
        printf("Enter Coefficient");
        scanf("%d",&coeff);
        node_ ptr = create_node(coeff,exp);
        if(p == NULL){
            p = ptr;
            last1 = ptr;
        }
        else{
            last1->next = ptr;
            last1 = ptr;
        }
        n--;
    }
    printf("Input exp 2");
    printf("Enter number of elements");
    scanf("%d",&n);
    while(n>0){
        printf("Enter Exponent");
        scanf("%d",&exp);
        printf("Enter Coefficient");
        scanf("%d",&coeff);
        node_ ptr = create_node(coeff,exp);
        if(q == NULL){
            q = ptr;
            last2 = ptr;
        }
        else{
            last2->next = ptr;
            last2 = ptr;
        }
        n--;
    }

}



void print(){
    node_ t = p;
    printf("%dx^%d ", p -> coeff, p -> exp);
    t = t -> next;
    while (t!=NULL) {
        printf("+ %dx^%d ", t -> coeff, t -> exp);
        t = t -> next;
    }
    printf("\n");
    t = q;
    printf("%dx%d ", t -> coeff, t -> exp);
    t = t -> next;
    while (t!= NULL) {
        printf("+ %dx^%d ", t -> coeff, t -> exp);
        t = t -> next;
    }   
    printf("\n");
}

void printr(){
    node_ t = r1;
    printf("%dx^%d ", t -> coeff, t -> exp);
    t = t -> next;
    while (t!= NULL) {
        printf("+ %dx^%d ", t -> coeff, t -> exp);
        t = t -> next;
    }   
    printf("\n");
}

void multiplyPolynomials() {
    node_ poly1 = p;
    node_ poly2 = q;
    // Multiply each term of poly1 with each term of poly2
    while (poly1 != NULL) {
        node_ tempPoly2 = poly2;
        while (tempPoly2 != NULL) {
            int coeff = poly1->coeff * tempPoly2->coeff;
            int exp = poly1->exp + tempPoly2->exp;
            node_ ptr = create_node(coeff,exp);
            
            if(r1 == NULL){
                r1 = ptr;
                last4 = ptr;
            }
            else{
                last4->next = ptr;
                last4 = ptr;
            }

            tempPoly2 = tempPoly2->next;
        }

        poly1 = poly1->next;
    }

}

void sub(){
    node_ t1=p,t2=q;

    while(t1 != NULL && t2!=NULL){
        node_ ptr;
        if(t1->exp == t2->exp){
            ptr = (node_)malloc(sizeof(struct node));
            ptr->coeff = t1->coeff - t2->coeff;
            ptr->exp = t1->exp;
            t1= t1->next; t2= t2->next;
        }
        else if(t1->exp > t2->exp){
            ptr = (node_)malloc(sizeof(struct node));
            ptr->coeff = t1->coeff;
            ptr->exp = t1->exp;
            t1= t1->next;
        }
        else if(t1->exp < t2->exp){
            ptr = (node_)malloc(sizeof(struct node));
            ptr->coeff = t2->coeff;
            ptr->exp = t2->exp;
            t2= t2->next;
        }

        if(r == NULL){
            r= ptr;
            last3 =ptr;
        }
        else{
            last3->next = ptr;
            last3=ptr;
        }
    }
    while(t1 != NULL){
        node_ ptr = (node_)malloc(sizeof(struct node));
        ptr->coeff = t1->coeff;
        ptr->exp = t1->exp;
        t1= t1->next;
        last3->next = ptr;
        last3=ptr;
    }
    while(t2 != NULL){
        node_ ptr = (node_)malloc(sizeof(struct node));
        ptr->coeff = t2->coeff;
        ptr->exp = t2->exp;
        t2= t2->next;
        last3->next = ptr;
        last3=ptr;
    }
}
void main(){
    input();
    print();
    multiplyPolynomials();
    printr();
}