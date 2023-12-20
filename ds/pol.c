#include <stdio.h>
#include <stdlib.h>

// Node structure to represent terms in the polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial linked list
void insertTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the polynomial
void display(struct Node* poly) {
    struct Node* current = poly;
    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* current1 = poly1;
    struct Node* current2 = poly2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            insertTerm(&result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
            insertTerm(&result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else {
            int newCoeff = current1->coefficient + current2->coefficient;
            insertTerm(&result, newCoeff, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        insertTerm(&result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insertTerm(&result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }

    return result;
}

// Main function to test polynomial addition
int main() {
    struct Node* poly1 = NULL;
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 5, 0);

    struct Node* poly2 = NULL;
    insertTerm(&poly2, 2, 2);
    insertTerm(&poly2, 3, 1);
    insertTerm(&poly2, 6, 0);

    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    struct Node* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial (Sum): ");
    display(result);

    return 0;
}