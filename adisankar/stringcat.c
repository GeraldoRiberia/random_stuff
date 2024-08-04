#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100] ="Word" ;
    char str2[100] ="Combo";
    int length = strlen(str1);
    for(int i =0; str2[i]!= '\0';i++, length++)
    {
        str1[length]=str2[i];
    }
    puts(str1);
}