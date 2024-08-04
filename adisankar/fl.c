#include<stdio.h>

int main(){
    FILE *f1,*f2,*f3;
    char str[256];
    f1 = fopen("file1.txt","r");
    f2 = fopen("file2.txt","r");
    f3 = fopen("merge.txt","w");
    while(feof(f1) == 0){
        char str[256];
        fscanf(f1,"%s",&str);
        fprintf(f3,"%s ",str);
    }
    while(feof(f2) == 0){
        char str[256];
        fscanf(f2,"%s",&str);
        fprintf(f3,"%s ",str);
    }
    printf("\n");

    return 0;
}