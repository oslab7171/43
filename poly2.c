#include <stdio.h>
#include <stdlib.h>

// Node structure for a term in a polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to insert a term into a polynomial (linked list)
struct Node* insertTerm(struct Node* head, int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to display a polynomial
void displayPolynomial(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
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
            result = insertTerm(result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
            result = insertTerm(result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else {
            // Exponents are equal, add coefficients
            int sum_coefficient = current1->coefficient + current2->coefficient;
            result = insertTerm(result, sum_coefficient, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    // Add remaining terms from poly1
    while (current1 != NULL) {
        result = insertTerm(result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    // Add remaining terms from poly2
    while (current2 != NULL) {
        result = insertTerm(result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }

    return result;
}

int main() {
    // Polynomial 1: 3x^3 + 2x^2 + 5x^1
    struct Node* poly1 = NULL;
    poly1 = insertTerm(poly1, 3, 3);
    poly1 = insertTerm(poly1, 2, 2);
    poly1 = insertTerm(poly1, 5, 1);

    // Polynomial 2: 4x^3 + 1x^2 + 2x^0
    struct Node* poly2 = NULL;
    poly2 = insertTerm(poly2, 4, 3);
    poly2 = insertTerm(poly2, 1, 2);
    poly2 = insertTerm(poly2, 2, 0);

    // Display polynomials
    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Add polynomials
    struct Node* result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}
