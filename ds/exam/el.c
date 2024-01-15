#include<stdio.h>

int sort(int a[],int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


void main(){
    int n;
    printf("Enter array size");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements : ");
    for(int i =0; i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,n);
    printf("Sorted array : ");
    for(int i =0; i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    int i =0, j=0;
    for(i =0; i<n; i++){
        int count = 1;
        for(j =i+1; j<n; j++){
            if(a[i] == a[j]){
                count++;
            }
            else{
                break;
            }
            
        }
        printf("Count of %d : %d \n",a[i],count);
        i =j-1;
    }

}