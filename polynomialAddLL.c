#include <stdio.h>
#include <stdlib.h>

// Node structure for a term in the polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new term node
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
        return;
    }

    struct Node* temp = *poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to add two polynomials represented as linked lists
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coeff = 0;
        int exp = 0;

        // If polynomial 1's exponent is greater
        if (poly1 && (!poly2 || poly1->exponent > poly2->exponent)) {
            coeff = poly1->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
        }
        // If polynomial 2's exponent is greater
        else if (poly2 && (!poly1 || poly2->exponent > poly1->exponent)) {
            coeff = poly2->coefficient;
            exp = poly2->exponent;
            poly2 = poly2->next;
        }
        // If exponents are equal, add coefficients
        else {
            coeff = poly1->coefficient + poly2->coefficient;
            exp = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        insertTerm(&result, coeff, exp);
    }

    return result;
}

// Function to display the polynomial represented by the linked list
void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Adding terms to polynomial 1: 3x^2 + 4x^1 + 5x^0
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 5, 0);

    // Adding terms to polynomial 2: 2x^3 + 3x^1 + 1x^0
    insertTerm(&poly2, 2, 3);
    insertTerm(&poly2, 3, 1);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    displayPolynomial(sum);

    return 0;
}
