#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
struct node* insert(int value, struct node *head)
{
    struct node *toInsert = (struct node*) malloc(sizeof(struct node));
    struct node *prevNode = (struct node*) malloc(sizeof(struct node));
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    toInsert->value = value;
    toInsert->next = NULL;
    if(head == NULL)
    {
        head = (struct node*) malloc(sizeof(struct node));
        head->value = value;
        head->next = NULL;
    }
    else if(value < head->value)
    {
        toInsert->next = head;
        head = toInsert;
    }
    else if(value == head->value)
        return head;
    else
    {
        prevNode = head;
        temp = head->next;
        while(temp != NULL && value > temp->value)
        {
            prevNode = temp;
            temp = temp->next;
        }
        if(temp == NULL)
        {
            prevNode->next = toInsert;
        }
        else if(temp->value == value)
            return head;
        else
        {
            toInsert->next = temp;
            prevNode->next = toInsert;
        }
    }
    return head;
}
struct node* delete(int val, struct node *head)
{
    struct node *prevNode = (struct node*) malloc(sizeof(struct node));
    prevNode = head;
    if(head == NULL)
    {
        return head;
    }
    if(head->value == val)
    {
        head = head->next;
    }
    else
    {
        while(prevNode->next != NULL)
        {
            if(val == prevNode->next->value)
            {
                prevNode->next = prevNode->next->next;
                break;
            }
            prevNode = prevNode->next;
        }
    }
    return head;
}
int main(int argc, char **argv)
{
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head = NULL;
    FILE* fp = NULL;
    char action;
    int value;
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
        if(action == 'd')
        {
            head = delete(value, head);
        }
        else if(action == 'i')
        {
            head = insert(value, head);
        }
        
    }
    fclose(fp);
    if(head == NULL)
    {
        printf("0\n");
        exit(0);
    }
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp = head;
    int count = 0;
    while(temp!= NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("%d\n",count);
    temp = head;
    while(temp!= NULL)
    {
        printf("%d\t", temp->value);
        temp = temp->next;
    }
    return 0;
}
