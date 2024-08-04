#include <stdio.h>
#include <string.h>

void reverseString(char* str)
{
	int i,l= 0;
	char ch;
	l = strlen(str);
	for (i = 0; i <(l-1)/2; i++) {

		ch = *(str+i);
		*(str+i) = *(str+l-1-i);
		*(str+l-1-i) = ch;
	}
}

int main()
{
	char str[100];
	printf("Enter a string: ");
    gets(str);
	reverseString(str);
	printf("Reverse of the string: %s\n", str);

	return 0;
}
