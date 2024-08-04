#include<stdio.h>
#include<string.h>
int main()
{
    int len,flag=0,i,j;
    char str[100],copy[100];
    printf("Enter a string to check whether it is PALINDROME or NOT");
    gets(str);
    len=strlen(str);
    for(i=len-1,j=0;i>=0;i--,j++)
    {
        copy[j]=str[i];
    }
    for(i=0;i<len-1;i++)
    {
    if(str[i]!=copy[j])
    {
    flag=1;
    }
    }
    if(flag==1)
    {
    printf("The string is PALINDROME");
    }else{
    printf("The string is NOT PALINDROME");
    }
    return 0;
}