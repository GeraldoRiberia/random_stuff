#include<stdio.h>
int cq[1000], f,r,n,item;
void cqin(){
    if(f==0 && r==n-1 || f == r+1){
        printf("Queue is full \n");
    }
    else if( f==-1 && r == -1){
        f = 0;
        r=0;
        printf("Enter element : ");
        scanf("%d",&cq[r]);
    }
    else{
        r=(r+1)%n;
        printf("Enter element :");
        scanf("%d",&cq[r]);
    }
}
void cqdel(){
    if(f==-1&& r==-1){
        printf("Queue is empty \n");
    }
    else if(f == r){
        printf("%d is deleted",cq[f]);
        f=-1;
        r=-1;
    }
    else{
        printf("%d is deleted \n",cq[f]);
        f=(f+1)%n;
    }
}

void cqdisplay(){
    if(f==-1&& r==-1){
        printf("Queue is empty \n");
    }
    else{
        if(f<=r){
            for(int i =f; i<=r;i++){
                printf("%d  ",cq[i]);
            }
        }
        else{
            for(int i =f; i<n;i++){
                printf("%d  ",cq[i]);
            }
            for(int i =r;i<f;i++){
                printf("%d  ",cq[i]);
            }
        }
        printf("\n");
    }
}
void main(){
    int ch;
    f=-1;r=-1;
    printf("Enter queue size : ");
    scanf("%d",&n);
    while(1){
        printf("1.Insert \n2.Delete\n3.Display\n0.Exit\nEnter selection : ");
        scanf("%d",&ch);
        if(ch == 0){printf ("Program exited! \n");break;}
        switch(ch){
            case 1 :cqin();
                    break;
            case 2 :cqdel();
                    break;
            case 3 :cqdisplay();
                    break;
            default :printf("Invalid Choice");
        }
    }
}