#include<stdio.h>

void sort(int *p, int n)
{
    int temp;
    for(int i =0; i<n-1; i++)
	{
		for(int j =0; j<n-i-1;j++)
		{
			if(*(p+j)>*(p+1+j))
			{
				temp =*(p+j);
				*(p+j) = *(p+1+j);
				*(p+j+1)=temp;
			}
		}
	}

}
void smallLarge(int *p, int n)
{
    printf("Largest : %d \nSmallest : %d \n", *p, *(p+n-1));
}

int main()
{
	int a[100],n,temp;
	int *p=a;
	printf("Enter size of array : ");
	scanf("%d",&n);
	for(int i =0; i<n; i++)
	{
		scanf("%d",(p+i));
	}
    sort(p,n);
	smallLarge(p,n);
	return 0;
}
