#include<stdio.h> 
#include<string.h>
void mystery(int a, int b) {
 int count = 0;
 while (a > b) {
 a = a - b;
 count++;
 }
 while (b > a) {
 b = b - a;
 count++;
 }
 printf("Number of subtractions: %d\n", count);
}
 int main()
{ 

    mystery(4096,128);
return 0; 
} 
