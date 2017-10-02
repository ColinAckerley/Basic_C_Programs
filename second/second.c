#include <stdio.h>
#include<stdlib.h>
int* sort(int toSort[], int size)
{
    int temp;
    int *sortedArray;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(toSort[j]>toSort[j+1])
            {
                temp=toSort[j];
                toSort[j]=toSort[j+1];
                toSort[j+1]=temp;
            }
        }
    }
    sortedArray = toSort;
    return sortedArray;
}
void print(int sortedArray[], int size)
{
    for(int i =0; i < size; i++)
    {
        printf("%d\t",sortedArray[i]);
    }
    printf("\n");
}
int main(int argc, char **argv)
{
    FILE* fp = NULL;
    int value;
    int size;
    int *sortedArray;
    char* filename = NULL;
    filename = argv[1];
    fp = fopen(filename, "r");
    fscanf(fp, "%d\n", &size);
    int arr[size];
    int curPos = 0;
    while(!feof(fp))
    {
        fscanf(fp, "%d\n", &value);
        arr[curPos] = value;
        curPos++;
    }
    sortedArray = sort(arr,size);
    print(sortedArray, size);
    fclose(fp);
    return 0;
}

