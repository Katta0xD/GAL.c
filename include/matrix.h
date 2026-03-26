#ifndef MATRIX_H
#define MATRIX_H
#endif

struct matrix
{
    int rows;    // m
    int columns; // n
    float **data;
};

struct matrix *getMatrix(int m, int n);

struct matrix *copyMatrix(struct matrix *M);

void freeMatrix(struct matrix *M);

void loadMatrix(struct matrix *M, float *coefficients);
/* coefficients array should be sorted by rows, it means: ((1,1), (1,2), ..., (1,n), (2, 1), (2,2), ..., (2, n), ...,
(m, 1), (m, 2), ..., (m, n) */

float *dumpCoefficients(struct matrix *M); // the array of coefficinets will be sorted by rows

void setCoefficient(struct matrix *M, int destRow, int destColumn, float coefficient);

float getCoefficient(struct matrix *M, int srcRow, int srcColumn);

// Functions for elemntary operations
void swapRows(struct matrix *M, int srcRow, int destRow);

void scaleRow(struct matrix *M, int row, float constant);
// assert(constant != 0);

void addScaledRow(struct matrix *M, int destRow, int srcRow, float constant);
// adds to destRow the result of multiplying srcRow * constant
