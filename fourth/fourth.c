#include <stdio.h>
#include <stdlib.h>
int **allocateBoardMem(int size)
{
    int **board = (int **)malloc(size * sizeof(int *));
    for (int row = 0; row < size; row++)
    {
        board[row] = (int *)malloc(size * sizeof(int));
    }
    return board;
}
void freeBoardMem(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(board[i]);
    }
    free(board);
}
void print(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}
int **multiply(int **boarda, int **boardb, int size)
{
    int sum = 0;
    int **newMatrix = allocateBoardMem(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum = 0;
            for (int k = 0; k <size; k++) {
                sum = sum + boarda[i][k] * boardb[k][j];
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
    int **curMatrix = allocateBoardMem(arrSize);
    int **ogMatrix = allocateBoardMem(arrSize);
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
    freeBoardMem(curMatrix, arrSize);
    freeBoardMem(ogMatrix, arrSize);
    return 0;
}
