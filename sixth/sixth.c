#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* compress(char line[])
{
    int start = 0;
    int end = 1;
    int curCompSpot = 0;
    int memCalc = 1;
    char *compressed = NULL;
    while(line[end] != '\0')
    {
        if(line[start] == line[end])
        {
            end++;
        }
        else
        {
            compressed = (char*) realloc(compressed, (memCalc * 2 ) +1);
            
            char tmp = (end - start) + '0';
            compressed[curCompSpot] = line[start];
            curCompSpot++;
            compressed[curCompSpot] = tmp;
            curCompSpot++;
            compressed[curCompSpot] = '\0';
            start = end;
            end = end + 1;
            memCalc++;
        }
    }
    compressed = (char*) realloc(compressed, (memCalc * 2) + 1 );
    char tmp = (end - start)+ '0';
    compressed[curCompSpot] = line[start];
    curCompSpot++;
    compressed[curCompSpot] = tmp;
    curCompSpot++;
    compressed[curCompSpot] = '\0';
    start = end;
    end = end + 1;
    return compressed;
}
int main(int argc, char **argv)
{
    if(argc > 2 || argc < 2)
    {
        printf("error\n");
        return 0;
    }
    int length = strlen(argv[1]);
    char *word = argv[1];
    for(int i = 0; i < length -1; i++)
    {
        if(word[i]=='0'||word[i]=='1'||word[i]=='2'||word[i]=='3'||word[i]=='5'||word[i]=='6'||word[i]=='7'||word[i]=='8'||word[i]=='9')
        {
            printf("error\n");
            exit(0);
        }
    }
    char* compressedString = compress(argv[1]);
    if(strlen(compressedString) > strlen(argv[1]))
    {
        printf("%s\n", argv[1]);
        free(compressedString);
    }
    else
    {
        printf("%s\n",compressedString);
        free(compressedString);
    }
    return 0;
}
