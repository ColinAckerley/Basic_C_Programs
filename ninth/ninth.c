#include <stdio.h>
#include <stdlib.h>
struct leaf
{
    int value;
    struct leaf *left;
    struct leaf *right;
};
struct leaf *createNewLeaf(int val)
{
    struct leaf *newLeaf = (struct leaf*) malloc(sizeof(struct leaf));
    newLeaf->value = val;
    newLeaf->right = NULL;
    newLeaf->left = NULL;
    return newLeaf;
}
int height = 1;
struct leaf *insert(struct leaf *head, int val, int resetHeight)
{
    if(resetHeight == 1)
        height = 1;
    if(head == NULL)
    {
        printf("inserted %d\n", height);
        return createNewLeaf(val);
    }
    if(val < head->value)
    {
        height++;
        head->left = insert(head->left, val, 0);
    }
    else if(val > head->value)
    {
        height++;
        head->right = insert(head->right, val, 0);
    }
    else if(val == head->value)
    {
        printf("duplicate\n");
        return head;
    }
    return head;
}
struct leaf* findMinLeaf(struct leaf *head)
{
    struct leaf *curLeaf = head;
    while(curLeaf->left != NULL)
    {
        curLeaf = curLeaf->left;
    }
    return curLeaf;
}
struct leaf *delete(struct leaf *head, int val)
{
    struct leaf *tmp = NULL;
    if(head == NULL)
    {
         printf("fail\n");
        return head;
    }
    if(val < head->value)
        head->left = delete(head->left, val);
    else if(val > head->value)
        head->right = delete(head->right, val);
    else
    {
        if(head->right == NULL)
        {
            tmp = head->left;
            free(head);
            printf("success\n");
            return tmp;
        }
        else if(head->left == NULL)
        {
            tmp = head->right;
            free(head);
            printf("success\n");
            return tmp;
        }
        else
        {
            tmp = findMinLeaf(head->right);
            head->value = tmp->value;
            head->right = delete(head->right, tmp->value);
        }
    }
    return head;
}
struct leaf* search(struct leaf *head, int val, int resetHeight)
{
    if(resetHeight == 1)
        height = 1;
    struct leaf *tmp = head;
    while(tmp != NULL)
    {
        if(tmp->value==val)
        {
            printf("present %d\n", height);
            return head;
        }
        else if(tmp->value>val)
        {
            height++;
            tmp = tmp->left;
        }
        else
        {
            height++;
            tmp = tmp->right;
        }
    }
    printf("absent\n");
    return head;
}
int main (int argc, char **argv)
{
    struct leaf *head = NULL;
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
        if(action == 'i')
        {
            head = insert(head, value, 1);
        }
        else if(action == 's')
        {
            head = search(head, value, 1);
        }
        else if(action == 'd')
            head = delete(head, value);
        else
            printf("error\n");
    }
    free(head);
    fclose(fp);
    return 0;
}
