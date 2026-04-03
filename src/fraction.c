#include "../include/fraction.h"
#include <math.h>
#include <stdio.h> // delete later, just for debug purpose
#include <stdlib.h>

fraction *newFraction() // don't know if this is gonna be needed, definition of fraction is in .h file so the main can
                        // do malloc(sizeof(fraction));
{
    fraction *F = malloc(sizeof(fraction));
    return F;
}

void setFractionFromReal(fraction *F, long double x)
{
    long double numerator = x; // 33.33333
    long long denominator = 1;

    printf("numerator:\n \tdecimal: %Lf\n\thexa: %LA\n", numerator, numerator);
    printf("round(numerator):\n \tdecimal: %Lf\n\thexa: %LA\n", roundl(numerator), roundl(numerator));
    while (fabsl(numerator - roundl(numerator)) > 1E-6L)
    {
        printf("numerator:\n \tdecimal: %Lf\n\thexa: %LA\n", numerator, numerator);
        printf("round(numerator):\n \tdecimal: %Lf\n\thexa: %LA\n", roundl(numerator), roundl(numerator));
        numerator = numerator * 10;     // 3333333
        denominator = denominator * 10; // 100000
        printf("\n");
    }
    printf("numerator:\n \tdecimal: %Lf\n\thexa: %LA\n", numerator, numerator);
    printf("round(numerator):\n \tdecimal: %Lf\n\thexa: %LA\n", roundl(numerator), roundl(numerator));
    long long gdc = getGCD((long long int)numerator, denominator);

    numerator /= gdc;
    denominator /= gdc;

    F->numerator = numerator;
    F->denominator = denominator;
}

long long getGCD(long long numerator, long long denominator)
{
    denominator = llabs(denominator);
    numerator = llabs(numerator);
    while (numerator != denominator && numerator * denominator != 0)
    {
        if (numerator > denominator)
            numerator = numerator % denominator;
        else
            denominator = denominator % numerator;
    }
    if (numerator > denominator)
        return numerator;
    else
        return denominator;
}
