#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
struct node* hashtable[10000];
int hash(int key)
{
    int hash =key%10000;
    if(hash < 0)
    {
        hash = hash * -1;
    }
    return hash;
}
void insert(int key)
{
    int hashedValue = hash(key);
    struct node *cur = (struct node*) malloc(sizeof(struct node));
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    cur->value = key;
    cur->next = NULL;
    if(hashtable[hashedValue] == NULL)
    {
        hashtable[hashedValue] = cur;
        printf("inserted \n");
    }
    else if (hashtable[hashedValue] != NULL)
    {
        int isDupe = 0;
        temp = hashtable[hashedValue];
        while(temp != NULL)
        {
            if(temp->value == key)
            {
                isDupe = 1;
                printf("duplicate\n");
                break;
                
            }
            temp = temp->next;
        }
        if(isDupe == 0)
        {
            temp = hashtable[hashedValue];
            hashtable[hashedValue] = cur;
            cur->next = temp;
            printf("inserted\n");
        }
    }
}
void search(int value)
{
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    int hashValue = hash(value);
    temp = hashtable[hashValue];
    int isPresent = 0;
    if(temp == NULL)
    {
        printf("absent\n");
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->value == value)
            {
                printf("present\n");
                isPresent = 1;
                break;
            }
            temp = temp->next;
        }
        if(isPresent == 0)
        {
            printf("absent\n");
        }
    }
}
int main(int argc, char **argv)
{
    char action;
    int value;
    FILE* fp = NULL;
    char* filename = NULL;
    filename = argv[1];
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("error\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp, "%c %d\n", &action, &value);
        if(action == 'i')
        {
            insert(value);
        }
        else if(action == 's')
        {
            search(value);
        }
        
    }
    fclose(fp);
    return 0;
}
