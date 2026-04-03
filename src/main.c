#include "../external/libfort/fort.h"
#include "../include/matrix.h"
#include "../include/row_reduction.h"
#include <stddef.h>
#include <stdio.h>

struct matrix *createMatrixAskingInput()
{
    int m, n;
    char x;
    bool extended = false;
    printf("Creacion de la matriz");
    printf("Es una matriz extendida [y/N]: ");
    scanf("%c", &x);
    if (x == 'Y' || x == 'y')
        extended = false;
    printf("Ingrese las dimesiones de su matriz (m * n): ");
    scanf("%d %d", &m, &n);

    struct matrix *M = newMatrix(m, n, extended);

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
    ft_table_t *table = ft_create_table();
    // ft_set_cell_prop(table, M->rows, M->columns, )

    printf("\n");
    for (int i = 0; i < M->rows; i++)
    {
        for (int j = 0; j < M->columns; j++)
            printf("%f", getCoefficient(M, i, j));
        printf("\n");
    }
}

int main()
{
    struct matrix *M = createMatrixAskingInput();
    printMatrix(M);

    struct matrix *REF = getRowEchelonForm(M);
    printMatrix(REF);

    struct matrix *RREF = getReducedRowEchelonForm(M);
    printMatrix(RREF);

    freeMatrix(M);
    freeMatrix(REF);
    freeMatrix(RREF);
    return 0;
}
