#include "../include/matrix.h"
#include <assert.h>

// corregir inicio del bucle interior; considerar division por 0; enviar filas nulas al final usando swapRows();
struct matrix *getRowEchelonForm(struct matrix *M)
{
    struct matrix *REF = copyMatrix(M);

    int i = 0;
    for (int j = 0; j < REF->columns && i < REF->rows; j++) // j and i define the pivot point
    {
        // swap row if it as a null coefficient in [i] for another that doesn't
        int exp = i;
        while (exp < REF->rows && REF->data[exp][j] == 0)
            exp++;
        if (exp != i)
            if (exp < REF->rows)
                swapRows(REF, i, exp);
            else
                continue;

        for (int k = i + 1; k < REF->rows; k++)
        {
            assert(REF->data[i][j] != 0);
            float scalar = (-1) * REF->data[k][j] / REF->data[i][j];
            addScaledRow(REF, k, i, scalar);
        }
        i++;
    }
    return REF;
}

struct matrix *getReducedRowEchelonForm(struct matrix *M)
{
    struct matrix *RREF = getRowEchelonForm(M);
    return RREF;
}
