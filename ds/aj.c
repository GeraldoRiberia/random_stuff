#include<stdio.h>
#include<stdlib.h>
struct node{
    int exp,coeff;
    struct node*next;
}*START1=NULL,*LAST1=NULL,*ptr,*t1=NULL,*t2=NULL,*t3=NULL,*START2=NULL,*LAST2=NULL,*START3=NULL,*LAST3=NULL,*p=NULL,*q=NULL;
void poly1(){
    
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the exponent\n");
    scanf("%d",&ptr->exp);
    printf("enter coeffecient\n");
    scanf("%d",&ptr->coeff);
    ptr->next=NULL;
    if(START1==NULL)
    {
        START1=ptr;
        LAST1=ptr;
    }
    else
    {
        LAST1->next=ptr;
        LAST1=ptr;
    }
}
void poly2(){
    
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the exponent\n");
    scanf("%d",&ptr->exp);
    printf("enter coeffeint\n");
    scanf("%d",&ptr->coeff);
    ptr->next=NULL;
    if(START2==NULL)
    {
        START2=ptr;
        LAST2=ptr;
    }
    else
    {
        LAST2->next=ptr;
        LAST2=ptr;
    }
}
void result(){
    p=START1;
    q=START2;
    while(p!=NULL&&q!=NULL)
    {
    if(p->exp==q->exp)
        {
            ptr=(struct node*)malloc(sizeof(struct node));
            ptr->coeff=p->coeff+q->coeff;
            ptr->exp=p->exp;
                    if(START3==NULL)
                    {
                     
                     START3=ptr;
                    LAST3=ptr;
                    }
                   else
                      {
                         LAST3->next=ptr;
                        LAST3=ptr;
                     }   
                    p=p->next;
                    q=q->next;
        }     
    else if(p->exp>q->exp)
            {
                   ptr=(struct node*)malloc(sizeof(struct node));
                ptr->coeff=p->coeff;
                ptr->exp=p->exp;
                if(START3==NULL)
                {
                 
                 START3=ptr;
                LAST3=ptr;
                }
               else
                  {
                     LAST3->next=ptr;
                    LAST3=ptr;
                 }p=p->next; 
                }
    else
            {
                  ptr=(struct node*)malloc(sizeof(struct node));
            ptr->coeff=q->coeff;
            ptr->exp=q->exp;
            if(START3==NULL)
            {
             
             START3=ptr;
            LAST3=ptr;
            }
           else
              {
                 LAST3->next=ptr;
                LAST3=ptr;
             }
             q = q->next;
            }
            
        
        
    }
    while(p!=NULL)
    {
          ptr=(struct node*)malloc(sizeof(struct node));
            ptr->coeff=p->coeff;
            ptr->exp=p->exp;
            if(START3==NULL)
            {
             
             START3=ptr;
            LAST3=ptr;
            }
           else
              {
                 LAST3->next=ptr;
                LAST3=ptr;
             }  
        p=p->next; 
            
    }
    while(q!=NULL)
    {
          ptr=(struct node*)malloc(sizeof(struct node));
            ptr->coeff=q->coeff;
            ptr->exp=q->exp;
            if(START3==NULL)
            {
             
             START3=ptr;
            LAST3=ptr;
            }
           else
              {
                 LAST3->next=ptr;
                LAST3=ptr;
             }
        q=q->next;
    }


  if(START1==NULL)
    {
        printf("no list");
        
    }
    else{
        
    t1=START1;
    printf("First Polynomial : ");
    while(t1!=NULL)
    {
        printf("%dx^%d ",t1->coeff,t1->exp);
        t1=t1->next;
    }
    printf("\n");
    
}
if(START2==NULL)
    {
        printf("no list");
        
    }
    else{
        
    t2=START2;
    printf("Second Polynomial : ");
    while(t2!=NULL)
    {
        printf("%dx^%d ",t2->coeff,t2->exp);
        t2=t2->next;
    }
    printf("\n");
    
}
if(START3==NULL)
    {
        printf("no list");
        
    }
    else{
        
    t3=START3;
    printf("Resultant Polynomial : ");
    while(t3!=NULL)
    {
        printf("%dx^%d ",t3->coeff,t3->exp);
        t3=t3->next;
    }
    printf("\n");
    
}
}
void main(){
    while(1){
    int ch;
    printf("\n1.enter 1st polynomial\n2.enter 2nd polynomial\n3show result\n4.exit\nENTER CHOICE\n");
    scanf("%d",&ch);
    switch (ch){
        case 1:poly1();
            break;
        case 2:poly2();
            break;
        case 3: result();
            break;
        case 4: exit(0);
            break;
        default:printf("invalid choice");
            break;
        
    }
}
}