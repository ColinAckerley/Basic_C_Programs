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
int checkDuplicates(int **matrix, int size)
{
    int newArray[size*size];
    int tmp = 0;
    for(int i =0; i < size; i++)
    {
        for(int j =0; j < size; j++)
        {
            newArray[tmp] = matrix[i][j];
            tmp++;
        }
    }
    for (int i = 0; i < size*size; i++)
    {
        for (int j = i + 1; j < size*size; j++)
        {
            if (newArray[i] == newArray[j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int checkVertical(int **matrix, int size)
{
    int mainSum = 0;
    int curSum = 0;
    for(int i = 0; i < size; i++)
    {
        mainSum += matrix[i][0];
    }
    for(int col = 1; col < size; col++)
    {
        for(int row = 0; row < size; row++)
        {
            curSum += matrix[row][col];
        }
        if(curSum != mainSum)
            return 0;
        else
            curSum = 0;
    }
    return 1;
}
int checkHorizontal(int **matrix, int size)
{
    int mainSum = 0;
    int curSum = 0;
    for(int i = 0; i < size; i++)
    {
        mainSum += matrix[0][i];
    }
    for(int row = 1; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            curSum += matrix[row][col];
        }
        if(curSum != mainSum)
            return 0;
        else
            curSum = 0;
    }
    return 1;
}
int checkDiagonal(int **matrix, int size)
{
    int sumA = 0;
    int sumB = 0;
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            
            if(i==j)  sumA+=matrix[i][j];
            if(i+j==size-1) sumB+=matrix[i][j];
        }
    }
    if(sumA == sumB)
        return 1;
    else
        return 0;
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
    int **matrix = allocateMatrixMem(arrSize);
    int curVal = 0;
    int col, row;
    row = 0;
    while(!feof(fp))
    {
        col = 0;
        while(col < arrSize)
        {
            fscanf(fp,"%d\n", &curVal);
            matrix[row][col] = curVal;
            col++;
        }
        row++;
    }
    if(checkVertical(matrix, arrSize) ==1 && checkHorizontal(matrix, arrSize) ==1 && (checkDiagonal(matrix, arrSize) ==1) && checkDuplicates(matrix, arrSize) ==1)
    {
        printf("magic\n");
    }
    else
        printf("not-magic\n");
    fclose(fp);
    freeMatrixMem(matrix, arrSize);
    return 0;
}
