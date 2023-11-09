#include<stdio.h>
int partition(int a[],int l,int h){
    int pivot = a[l];
    int i=l,j=h;
    while(i<j){
        do{
            i++;
        }while(a[i]<= pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j){
            int temp= a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    int temp= a[l];
    a[j]=a[l];
    a[l]=temp;
    return j;
}
void qsort(int a[],int l, int h){
    int j;
    if(l<h){
        j=partition(a,l,h);
        qsort(a,l,j);
        qsort(a,j+1,h);

    }
}



void main(){
    int n;
    printf("Enter limit of array");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements :");
    for(int i =0; i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,0,n);
    printf("Sorted elements :");
    for(int i =0; i<n;i++){
        printf("%d  ",a[i]);
    }

    
    
}