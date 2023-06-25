#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100], str2[100];
    fgets(str1,100,stdin);
    fgets(str2,100,stdin);
    int length = strcspn(str1,'\n');
    for(int i =0; str2[i]!= '\0';i++, length++)
    {
        if(str1[length]=='\n')
        {
            str1[length]='0';
        }
        else
        {
            str1[length]=str2[i];
        }
    }

    puts(str1);
}