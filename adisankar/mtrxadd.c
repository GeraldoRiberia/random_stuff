#include <stdio.h>
int main()
	{
	int a[20][20],b[20][20],c[20][20],i,j,rows,columns;
	printf("Enter number of rows :");
	scanf("%d",&rows);
	printf("Enter number of columns :");
	scanf("%d",&columns);
	printf("Enter elements of A\n");
	for(i=0;i<rows;i++)
		{
		for (j=0;j<columns;j++)
			{
			printf("Enter element at row %d column %d: ", i+1,j+1);
			scanf("%d",&a[i][j]);
			}
		}
	printf("Enter elements of B\n");
	for(i=0;i<rows;i++)
		{
		for (j=0;j<columns;j++)
			{
			printf("Enter element at row %d column %d: ", i+1,j+1);
			scanf("%d",&b[i][j]);
			}
		}
		
	for(i=0;i<rows;i++)
		{
		for (j=0;j<columns;j++)
			{
			c[i][j] = a[i][j] + b[i][j];
			}
		}
	
	for(i=0;i<rows;i++)
		{
		for (j=0;j<columns;j++)
			{
			printf("%d ", c[i][j]);
			}
		printf("\n");
		}
	return 0;
	}