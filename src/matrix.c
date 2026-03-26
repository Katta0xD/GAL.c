#include "../include/matrix.h"
#include <stdlib.h>

struct matrix *getMatrix(int m, int n)
{
    struct matrix *M = malloc(sizeof(struct matrix));
    (*M).rows = m;    // or M->rows = m;
    (*M).columns = n; // or M->columns = n;
    float **matrix = malloc(sizeof(float *) * m);
    for (int i = 0; i < m; i++)
    {
        matrix[i] = malloc(sizeof(float) * n);
    }
    (*M).data = matrix;
    return M;
}

struct matrix *copyMatrix(struct matrix *M)
{
    struct matrix *CP = getMatrix((*M).rows, (*M).columns);
    for (int i = 0; i < (*M).rows; i++)
    {
        for (int j = 0; j < (*M).columns; j++)
        {
            (*CP).data[i][j] = (*M).data[i][j];
        }
    }
    return CP;
}

void freeMatrix(struct matrix *M)
{
    if (M == NULL)
        return;

    for (int i = 0; i < (*M).rows; i++)
    {
        free((*M).data[i]);
    }
    free(M->data);
    free(M);
}

void loadMatrix(struct matrix *M,
                float *coefficients) // coefficients array should be sorted By row, it means: ((1,1), (1,2), ..., (1,
                                     // n), (2, 1), (2,2), ..., (2, n), ..., (m, 1), (m, 2), ..., (m, n)
{
    for (int i = 0; i < (*M).rows; i++)
    {
        for (int j = 0; j < (*M).columns; j++)
        {
            (*M).data[i][j] = coefficients[i * (*M).columns + j];
        }
    }
}

float *dumpCoefficients(struct matrix *M)
{
    float *coefficients = malloc(sizeof(float) * (*M).columns * (*M).rows);
    for (int i = 0; i < (*M).rows; i++)
    {
        for (int j = 0; j < (*M).columns; j++)
        {
            coefficients[i * (*M).columns + j] = (*M).data[i][j];
        }
    }
    return coefficients;
}

void setCoefficient(struct matrix *M, int destRow, int destColumn, float coefficient)
{
    (*M).data[destRow][destColumn] = coefficient;
}

float getCoefficient(struct matrix *M, int srcRow, int srcColumn)
{
    return (*M).data[srcRow][srcColumn];
}

// Functions for elemntary operations
void swapRows(struct matrix *M, int srcRow, int destRow)
{
    float *aux = (*M).data[srcRow];
    (*M).data[srcRow] = (*M).data[destRow];
    (*M).data[destRow] = aux;
}

void scaleRow(struct matrix *M, int row, float constant)
// assert(constant != 0);
{
    for (int i = 0; i < (*M).columns; i++)
    {
        (*M).data[row][i] = (*M).data[row][i] * constant;
    }
}

void addScaledRow(struct matrix *M, int destRow, int srcRow,
                  float constant) // adds to destRow the result of multiplying srcRow * constant
{
    for (int i = 0; i < (*M).columns; i++)
    {
        (*M).data[destRow][i] = (*M).data[destRow][i] + (*M).data[srcRow][i] * constant;
    }
}
