#include <stdio.h>
#include <stdlib.h>
int **allocateMatrixMem(int size)
{
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int row = 0; row < size; row++)
    {
        matrix[row] = (int *)malloc(size * sizeof(int));
    }
    return matrix;
}
void freeMatrixMem(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
void print(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
int **multiply(int **matrixa, int **matrixb, int size)
{
    int sum = 0;
    int **newMatrix = allocateMatrixMem(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum = 0;
            for (int k = 0; k <size; k++) {
                sum = sum + matrixa[i][k] * matrixb[k][j];
            }
            newMatrix[i][j] = sum;
        }
    }
    return newMatrix;
}
int main(int argc, char **argv)
{
    int arrSize = 0;
    FILE* fp = NULL;
    char* filename = NULL;
    filename = argv[1];
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("error\n");
        exit(0);
    }
    fscanf(fp,"%d\n", &arrSize);
    int **curMatrix = allocateMatrixMem(arrSize);
    int **ogMatrix = allocateMatrixMem(arrSize);
    int curVal = 0;
    int col, row;
    row = 0;
    int power = 0;
    while(!feof(fp))
    {
        col = 0;
        while(col < arrSize)
        {
            fscanf(fp,"%d\n", &curVal);
            ogMatrix[row][col] = curVal;
            col++;
        }
        row++;
        if(row == arrSize)
        {
            fscanf(fp,"%d\n", &power);
        }
    }
    curMatrix = ogMatrix;
    while(power > 1)
    {
        curMatrix = multiply(ogMatrix, curMatrix, arrSize);
        power--;
    }
    print(curMatrix, arrSize);
    fclose(fp);
    freeMatrixMem(curMatrix, arrSize);
    freeMatrixMem(ogMatrix, arrSize);
    return 0;
}
