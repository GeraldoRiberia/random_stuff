#include<stdio.h>
int main()
{
    char str;
    printf("Enter string"); 
    gets(str);
    char *p = &str;
    printf("%p", &str);
    printf("%p",p);

} 