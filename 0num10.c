#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

int** createMatrix(int, int);
void printMatrix(int**, int, int);
void freeMatrix(int**, int);
void randomizeMatrix(int**, int, int);
int** matrixMultiplication(int**, int, int, int**, int, int);
int determinant(int*, int**, int, int);

int main(int argc, const char* argv[]) {

    int row1, col1, row2, col2, determinant_value;
    int** massive1, ** massive2, ** multipleMassive;
    srand((unsigned)time(NULL));          

    printf("Input number of the first matrix rows:\n");
    scanf("%d", &row1);
    printf("Input number of the first matrix collumns:\n");
    scanf("%d", &col1);
    printf("Input number of the second matrix rows:\n");
    scanf("%d", &row2);
    printf("Input number of the second matrix collumns:\n");
    scanf("%d", &col2);
    printf("\v");


    massive1 = createMatrix(row1, col1);
    randomizeMatrix(massive1, row1, col1);
    if (massive1 != NULL) {
        printf("First matrix:\n");
        printMatrix(massive1, row1, col1);
    }
    else
    {
        printf("Error! Cant allocate memory\n");
    }

    massive2 = createMatrix(row2, col2);
    if (massive2 != NULL) {
        randomizeMatrix(massive2, row2, col2);
        printf("Second matrix:\n");
        printMatrix(massive2, row2, col2);
    }
    else
    {
        printf("Error! Cant allocate memory\n");
    }

    multipleMassive = matrixMultiplication(massive1, row1, col1, massive2, row2, col2);
    if (multipleMassive != NULL)
    {
        printf("Multiple matrix:\n");
        printMatrix(multipleMassive, row1, col2);
    }
    else
    {
        printf("Error! Number of the first matrix collumns must be equal rows of the second\n");
    }



    switch (determinant(&determinant_value, massive1, row1, col1))
    {
    case 0:
        printf("Determinant for first matrix: %d\n", determinant_value);
        break;
    default:
        printf("Cant search determinant for first matrix\n");
    }

    switch (determinant(&determinant_value, massive2, row2, col2))
    {
    case 0:
        printf("Determinant for second matrix: %d\n", determinant_value);
        break;
    default:
        printf("Cant search determinant for second matrix\n");
    }






    freeMatrix(massive1, row1);
    freeMatrix(massive2, row2);
    if (multipleMassive != NULL) freeMatrix(multipleMassive, row1);

    return 0;
}



void randomizeMatrix(int** massive, int rows, int collumns)
{
    int i = 0, j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < collumns; j++)
        {
           
            massive[i][j] = rand() % 200 - 100;
        }
    }
}


int** createMatrix(int rows, int collumns) {
    int i, ** massive;
    massive = calloc(rows, sizeof(int*));
    if (massive == NULL)
    {
        return NULL;
    }

    for (i = 0; i < rows; i++)
    {
        massive[i] = calloc(collumns, sizeof(int));
        if (massive[i] == NULL)
        {
            freeMatrix(massive, rows);
            return NULL;
        }
        
    }

    return massive;
}

void printMatrix(int** massive, int rows, int collumns)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < collumns; j++)
        {
            printf("%-10d", massive[i][j]); 
        }
        printf("\n\n\n"); 
    }
    printf("\n\n\n");
}

void freeMatrix(int** massive, int rows)
{
    int i;
    for (i = 0; i < rows; i++)
    {
        if (massive[i] != NULL) free(massive[i]);
    }

    free(massive);
}


int** matrixMultiplication(int** massive1, int rows1, int collumns1, int** massive2, int rows2, int collumns2)
{
    int** massive, rows, collumns, i, j, k;
    if (collumns1 != rows2) return NULL;

    rows = rows1;
    collumns = collumns2;
    massive = createMatrix(rows, collumns);

    for (i = 0; i < collumns; i++)
    {
        for (j = 0; j < rows; j++)
        {
            for (k = 0; k < collumns1; k++)
            {
                massive[j][i] += massive1[j][k] * massive2[k][i];
            }
        }

    }

    return massive;
}


int determinant(int* result, int** matrix, int rows, int collumns)
{
    int** newMatrix, Ai, Aj, matrixi, matrixj, newMatrixi, newMatrixj, determinant_value = 0, buferResult = 0;

    if (rows != collumns) return 1;
    if (rows == 1)
    {
        *result = matrix[0][0];
        return 0;
    }
    else if (rows == 2)
    {
        *result = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        return 0;
    }

    newMatrix = createMatrix(rows - 1, collumns - 1); 
    if (newMatrix == NULL)
    {
        return -1;
    }

    Ai = 0;
    for (Aj = 0; Aj < collumns; Aj++)
    {
        for (matrixi = 0; matrixi < collumns; matrixi++)
        {
            if (matrixi == Ai) continue;
            for (matrixj = 0; matrixj < collumns; matrixj++)
            {
                if (matrixj == Aj) continue;
                newMatrixi = matrixi > Ai ? matrixi - 1 : matrixi;
                newMatrixj = matrixj > Aj ? matrixj - 1 : matrixj;

                newMatrix[newMatrixi][newMatrixj] = matrix[matrixi][matrixj];
            }
        }

        determinant(&buferResult, newMatrix, rows - 1, collumns - 1);
        determinant_value += (pow(-1, Ai + Aj) * matrix[Ai][Aj] * buferResult);
    }

    *result = determinant_value;
    freeMatrix(newMatrix, rows - 1); 
    return 0;
}
