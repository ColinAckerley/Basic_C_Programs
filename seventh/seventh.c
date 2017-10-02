#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    int i = 1;
    while(argv[i] != NULL)
    {
        int length = strlen(argv[i]);
        char* curWord = argv[i];
        printf("%c",curWord[length -1]);
        i++;
    }
    printf("\n");
    return 0;
}
