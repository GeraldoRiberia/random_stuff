#include<stdio.h>
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
	for(int i =0; i<n; i++)
	{
		printf("%d, ",*(p+i));
	}
	return 0;
}