#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int coef;
    int exp;
    struct poly *next;
}*p1=NULL,*p2=NULL,*re=NULL;

typedef struct poly poly_;

poly_* create_node(int coef, int exp){
    poly_ *ptr = (poly_*)malloc(sizeof(poly_));
    ptr->coef= coef;
    ptr->exp= exp;
    ptr->next= NULL;
    return ptr;
}

void display() {
    poly_ *p = p1;
    printf("%dx%d ", p -> coef, p -> exp);
    p = p -> next;
    while (p!=NULL) {
        printf("+ %dx%d ", p -> coef, p -> exp);
        p = p -> next;
    }
    printf("\n");
    p = p2;
    printf("%dx%d ", p -> coef, p -> exp);
    p = p -> next;
    while (p!= NULL) {
        printf("+ %dx%d ", p -> coef, p -> exp);
        p = p -> next;
    }   
    printf("\n");
    printf("Sum : ");
    p = re;
    printf("%dx%d ", p -> coef, p -> exp);
    p = p -> next;
    while (p != NULL) {
        printf("+ %dx%d ", p -> coef, p -> exp);
        p = p -> next;
    }
    printf("\n");

}

void poly_add(){
    poly_ *ptr = (poly_*)malloc(sizeof(poly_));
    poly_ *t1 = p1;
    poly_ *t2 = p2;
    while(t1!= NULL && t2 != NULL){
        if(t1->exp == t2->exp){
            ptr = create_node(t1->coef+t2->coef, t1->exp);
            t1= t1->next;
            t2= t2->next;
        }
        else if ( t1->exp > t2->exp){
            ptr = create_node(t1->coef,t1->exp);
            t1= t1->next;
        }
        else{
            ptr =create_node(t2->coef,t2->exp);
            t2= t2->next;
        }
        if(re == NULL){
            re = ptr;
        }
        else{
            re->next=ptr;
        }
    }
    while(t1 != NULL){
        ptr = create_node(t1->coef,t1->exp);
        re->next = ptr;
        t1= t1->next;
    }
    while(t2 != NULL){
        ptr =create_node(t2->coef,t2->exp);
        re->next = ptr;
        t2= t2->next;
    }
}

void exp_in(){
    int exp, coeff,n;
    printf("Input exp 1");
    printf("Enter number of elements");
    scanf("%d",&n);
    while(n>0){
        printf("Enter Exponent");
        scanf("%d",&exp);
        printf("Enter Coefficient");
        scanf("%d",&coeff);
        poly_ *ptr = create_node(coeff,exp);
        if(p1 == NULL){
            p1 = ptr;
        }
        else{
            p1->next = ptr;
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
        poly_ *ptr = create_node(coeff,exp);
        if(p2 == NULL){
            p2 = ptr;
        }
        else{
            p2->next = ptr;
        }
        n--;
    }

}

void main(){
    int ch;
    while(1){   
        printf("1.Input expressions\n2.Display expressions\n3. Add Polynomials\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : exp_in();
                    break;
            case 2 :display();
                    break;
            case 3 : poly_add();
                    break;
        }
    }
}