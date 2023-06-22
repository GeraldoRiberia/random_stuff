#include<stdio.h>
int main()
{   
    int k;
    printf("Enter size for pattern \n");
    scanf("%d",&k);
    //k =5;
    for(int i =1; i<k;i++)
    {
        for(int j =1; j<=k-i; j++)
        {
            printf(" ");
        }
        for(int j = k-i; j<k; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    for(int i =k; i>0;i--)
    {
        for(int j =1; j<=k-i; j++)
        {
            printf(" ");
        }
        for(int j = k-i; j<k; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}

/*
Enter size for pattern 
6
     * 
    * * 
   * * * 
  * * * * 
 * * * * * 
* * * * * * 
 * * * * * 
  * * * * 
   * * * 
    * * 
     * 
*/