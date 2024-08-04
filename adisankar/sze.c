#include<stdio.h>
#include<string.h>

void main(){
    char str1[256];
    char str2[256];
    gets(str1);
    gets(str2);
    int i =0;
    int j=strlen(str1);
    while(str1[i]!='\0')
    {
        str1[j+i]=str2[i];
        i++;
    }
    printf("%s \n",str1);
}