#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int numbers[MAX_SIZE];
    int n, i, num, found = 0;

    // Input the size of the list
    printf("Enter the size of the list: ");
    scanf("%d", &n);

    // Input the elements of the list
    printf("Enter the numbers in the list:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Input the number to search or insert
    printf("Enter the number to search or insert: ");
    scanf("%d", &num);

    // Check if the number is present in the list
    for (i = 0; i < n; i++) {
        if (numbers[i] == num) {
            found = 1;
            printf("Number %d found at location %d\n", num, i + 1);
            break;
        }
    }

    // If the number is not found, insert it at the end
    if (!found) {
        numbers[n] = num;
        n++; // Increase the size of the list
        printf("Number %d inserted at the end\n", num);
    }

    // Print the updated list
    printf("Updated list: ");
    for (i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
