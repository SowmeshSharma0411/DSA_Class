#include <stdio.h>
#include "poly.h"

int main()
{
    POLYNOMIAL p1, p2, p3;
    initPolynomial(&p1);
    initPolynomial(&p2);
    initPolynomial(&p3);

    printf("Your Poly should be of the form : Ax^2y^2 + Bxy^2 + Cx^2y + Dxy \n");

    printf("First Polynomial-> ");
    createPolynomial(&p1);
    display(&p1);

    printf("Second Polynomial-> ");
    createPolynomial(&p2);
    display(&p2);

    addPolynomial(&p1, &p2, &p3);
    printf("\nResultant Polynomial-> ");
    display(&p3);

    destroyPolynomial(&p1);
    destroyPolynomial(&p2);
    destroyPolynomial(&p3);
}