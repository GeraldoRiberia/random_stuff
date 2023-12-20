#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*ptr,*start=NULL,*last=NULL,*t=NULL;
void create_list()
{
    int ch,i,n;
    printf("Enter number of nodes");
    scanf("%d,&n");
    for(i=0;i<n;i++)
        {
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("Enter data");
        scanf("%d",&ptr->data);
        ptr->next=NULL;
            if(start==NULL)
                {
                 start=ptr;
                 last=ptr;
                }
            else
                {
                    last->next=ptr;
                    last=ptr;
                }
        }
        printf("entered linked list is\t");
        t=start;
        while(t!=NULL)
            {
                printf("%d",t->data);
                t=t->next;
            }
}
void main()
{
    int ch;
    
    printf("make choice\n1.create list\n2.delete\n");
    scanf("%d",&ch);
    switch (ch)
            {
                case 1:create_list();
                  break;
            }

}