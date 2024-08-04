#include<stdio.h>

int main()
{
    FILE *ftpr;
    ftpr = fopen("cum.txt","w");
    fprintf(ftpr,"Hello \n");
    fprintf(ftpr, "world");
    
}