#include "../include/matrix.h"

// corregir inicio del bucle interior; considerar division por 0; enviar filas nulas al final usando swapRows();
struct matrix *getRowEchelonForm(struct matrix *M)
{
    struct matrix *REF = copyMatrix(M);
    for (int i = 0; i < (*REF).rows && i < (*REF).columns; i++)
    {
        for (int j = i; j < (*REF).rows; j++)
        {
            float scalar = (-1) * (*REF).data[i][j] / (*REF).data[i][i];
            addScaledRow(REF, j, i, scalar);
        }
    }
    return REF;
}

struct matrix *getReducedRowEchelonForm(struct matrix *M)
{
    struct matrix *RREF = getRowEchelonForm(M);
    for (int i = (RREF->rows >= RREF->columns) ? RREF->rows : RREF->columns; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            float scalar = (-1) * RREF->data[i][j] / RREF->data[i][i];
            addScaledRow(RREF, j, i, scalar);
        }
    }
    return RREF;
}
