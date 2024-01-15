#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};

// Function to insert a term into a polynomial
void insertTerm(struct Term **poly, int coeff, int exp) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;

    if (*poly == NULL) {
        // If the polynomial is empty, set the new term as the head
        *poly = newTerm;
    } else {
        // Otherwise, insert the term at the end of the polynomial
        struct Term *last = *poly;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newTerm;
    }
}

// Function to multiply two polynomials
struct Term *multiplyPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;

    // Multiply each term of poly1 with each term of poly2
    while (poly1 != NULL) {
        struct Term *tempPoly2 = poly2;
        while (tempPoly2 != NULL) {
            // Multiply coefficients and add exponents
            int coeff = poly1->coefficient * tempPoly2->coefficient;
            int exp = poly1->exponent + tempPoly2->exponent;

            // Insert the result term into the result polynomial
            insertTerm(&result, coeff, exp);

            tempPoly2 = tempPoly2->next;
        }

        poly1 = poly1->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term *poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to free memory allocated for a polynomial
void freePolynomial(struct Term *poly) {
    while (poly != NULL) {
        struct Term *temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    // Example polynomials: 3x^2 + 2x + 1 and 2x^3 + 4x^2
    struct Term *poly1 = NULL;
    insertTerm(&poly1, 12, 3);
    insertTerm(&poly1, 4, 2);
    insertTerm(&poly1, 1, 0);

    struct Term *poly2 = NULL;
    insertTerm(&poly2, 6, 3);
    insertTerm(&poly2, 2, 2);
    insertTerm(&poly2, 6, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Multiply the polynomials
    struct Term *result = multiplyPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    // Free allocated memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
