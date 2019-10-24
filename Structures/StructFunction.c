#include<stdio.h>

typedef struct Complex{
    int real;
    int imag;
}COMPLEX;

COMPLEX addComplex(COMPLEX c1, COMPLEX c2)
{
    COMPLEX c3;
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;
    return c3;
}

COMPLEX subComplex(COMPLEX c1, COMPLEX c2)
{
    COMPLEX c3;
    c3.real = c1.real - c2.real;
    c3.imag = c1.imag - c2.imag;
    return c3;
}


void main()
{
    COMPLEX c1 = {1, 2};
    COMPLEX c2 = {2, 3};
    COMPLEX add = addComplex(c1, c2);
    COMPLEX sub = subComplex(c1, c2);
    printf("\n%d + %di", add.real, add.imag);
    printf("\n%d +%di", sub.real, sub.imag);
}