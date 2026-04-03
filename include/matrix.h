#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

struct matrix
{
    int rows;    // m
    int columns; // n
    bool extended;
    float **data;
};

struct matrix *newMatrix(int m, int n, bool x);

struct matrix *copyMatrix(struct matrix *M);

void freeMatrix(struct matrix *M);

void loadMatrix(struct matrix *M, float *coefficients);
/* coefficients array should be sorted by rows, it means: ((1,1), (1,2), ..., (1,n), (2, 1), (2,2), ..., (2, n), ...,
(m, 1), (m, 2), ..., (m, n). edit: extended bool was aded later, so independent terms must be added at the end of each
row, following the structure like they are an additional column.*/

float *dumpCoefficients(struct matrix *M); // the array of coefficinets will be sorted by rows

void setCoefficient(struct matrix *M, int destRow, int destColumn,
                    float coefficient); // b_n must be refered to as a_(rows-1, n)

float getCoefficient(struct matrix *M, int srcRow, int srcColumn); // b_n must be refered to as a_(rows, n)

// Functions for elemntary operations
void swapRows(struct matrix *M, int srcRow, int destRow);

void scaleRow(struct matrix *M, int row, float constant);
// assert(constant != 0);

void addScaledRow(struct matrix *M, int destRow, int srcRow, float constant);
// adds to destRow the result of multiplying srcRow * constant

#endif
