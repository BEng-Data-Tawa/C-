#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int acol, arow, bcol, brow;

    // get user input
    printf("Enter #A row: ");
    scanf("%d", &arow);

    printf("Enter #A col: ");
    scanf("%d", &acol);

    printf("Enter #B row: ");
    scanf("%d", &brow);

    printf("Enter #B col: ");
    scanf("%d", &bcol);

    int A[arow][acol];
    int B[brow][bcol];

    // populate A
    for (int i = 0; i < arow; i++) {
        for (int j = 0; j < acol; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // populate B
    for (int i = 0; i < brow; i++) {
        for (int j = 0; j < bcol; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // print matrices
    printf("\nMatrix A:\n");
    for (int i = 0; i < arow; i++) {
        for (int j = 0; j < acol; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < brow; i++) {
        for (int j = 0; j < bcol; j++) {
            printf("%4d", B[i][j]);
        }
        printf("\n");
    }

    // matrix product
    if (acol == brow) {
        int product[arow][bcol];
        int sum = 0;

        for (int i = 0; i < arow; i++) {
            for (int j = 0; j < bcol; j++) {
                sum = 0;
                for (int k = 0; k < acol; k++) {
                    sum += A[i][k] * B[k][j];
                }
                product[i][j] = sum;
            }
        }

        // print result
        printf("\nMatrix Product:\n");
        for (int i = 0; i < arow; i++) {
            for (int j = 0; j < bcol; j++) {
                printf("%4d", product[i][j]);
            }
            printf("\n");
        }

    } else {
        printf("\nCANNOT MULTIPLY: columns of A != rows of B\n");
    }

    return 0;
}
