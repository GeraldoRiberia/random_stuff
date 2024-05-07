#include<stdio.h>

void main(){
    int key,flag=0,i;
    int a[20]={1,52,23,41,5,8,10};
    printf("Enter no to check : ");
    scanf("%d",&key);

    for( i =0; a[i]!='\0'; i++){
        if(a[i]==key){
            printf("Element found at %d \n", i);
            flag =1; break;
        }
    }

    if(flag == 0){
        a[i]=key;
        printf("Updated list : ");
        for(int i =0; a[i]!='\0' ; i++){
            printf("%d  ",a[i]);
        }
    }
}