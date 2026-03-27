#include "../include/matrix.h"
#include "../include/row_reduction.h"
#include <stdio.h>

struct matrix *createMatrixAskingInput()
{
    int m, n;
    printf("Ingrese las dimesiones de su matriz (m * n): ");
    scanf("%d %d", &m, &n);

    struct matrix *M = newMatrix(m, n);

    for (int i = 0; i < M->rows; i++)
    {
        for (int j = 0; j < M->columns; j++)
        {
            float input;
            printf("Ingrese el coeficiente para M[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &input);
            setCoefficient(M, i, j, input);
        }
    }

    return M;
}

void printMatrix(struct matrix *M)
{
    printf("\n");
    for (int i = 0; i < M->rows; i++)
    {
        for (int j = 0; j < M->columns; j++)
            printf("[%g]", getCoefficient(M, i, j));
        printf("\n");
    }
}

int main()
{
    struct matrix *M = createMatrixAskingInput();
    printMatrix(M);

    struct matrix *REF = getRowEchelonForm(M);
    printMatrix(REF);

    freeMatrix(M);
    freeMatrix(REF);
    return 0;
}
