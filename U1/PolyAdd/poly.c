#include <stdio.h>
#include "poly.h"

int main()
{
    POLYNOMIAL pobj1, pobj2, pobj3;

    initPolynomial(&pobj1);
    initPolynomial(&pobj2);
    initPolynomial(&pobj3);

    printf("Polynomial1\n");
    createPolynomial(&pobj1);
    display(&pobj1);

    printf("Polynomial2\n");
    createPolynomial(&pobj2);
    display(&pobj2);

    addPolynomial(&pobj1, &pobj2, &pobj3);
    printf("\nResultant Polynomial\n");
    display(&pobj3);

    destroyPolynomial(&pobj1);
    destroyPolynomial(&pobj2);
    destroyPolynomial(&pobj3);
}