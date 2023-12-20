#include<stdio.h>
int top =-1;
void push(int stk[],int n){
    if(top == n-1){
        printf("Stack is full \n");
    }
    else{
        int e;
        printf("Enter element : ");
        scanf("%d",&e);
        top++;
        stk[top]=e;
    }
}
void pop(int stk[],int n){
    if(top == -1){
        printf("stack is empty \n");
    }
    else{
        printf("Deleted element : %d \n", stk[top]);
        top--;
    }
}
void display(int stk[], int n){
    if(top == -1){
        printf("stack is empty \n");
    }
    else{
        for(int i =0; i<= top;i++){
            printf("%d ",stk[i]);
        }
    printf("\n");
    }
}
int main(){
    int n,ch;
    printf("Enter size of stack : ");
    scanf("%d", &n);
    int stk[n];
    while(1){
        printf("1. Push \n2. Pop\n3. Display \n0. exit \n");
        scanf("%d",&ch);
        if(ch == 0){
            printf("Program exited!");
            break;
        }

        switch(ch){
            case 1 : push(stk,n);
                    break;
            case 2 : pop(stk,n);
                    break;
            case 3 : display(stk,n);
                    break;
            default : printf("Invalid choice \n");
        }
    }
    return 0;
}