#ifndef FRACTION_H
#define FRACTION_H

struct fraction
{
    long long numerator;
    long long denominator;
};

typedef struct fraction fraction;

fraction *newFraction();

void setFractionFromReal(fraction *F, long double x);

long double getDouble(fraction *F);

// here for testing and debugin, delete later. this function will be used only internally.
long long getGCD(long long numerator, long long denominator);

#endif
