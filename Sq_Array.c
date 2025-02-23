#include <stdio.h>
#include <stdlib.h>

typedef unsigned long Status;
#define SQ_INIT_LENGTH 128
#define OK 1
#define ERROR 0

typedef struct SQ_Array
{
    int *elem;
    int length;
    int listsize;
}SQ_ARRAY;

Status SQ_Init(SQ_ARRAY *list)
{
    int listsize = sizeof(int)*SQ_INIT_LENGTH;
    list->elem = (int *)malloc(sizeof(int)*SQ_INIT_LENGTH);
    if (NULL == list->elem)
    {
        return ERROR;
    }
    list->length = SQ_INIT_LENGTH;
    list->listsize = listsize;
    return  OK;
}

int main()
{
    SQ_ARRAY g_Squence;
    SQ_Init(&g_Squence);
    printf("Success!\r\n");
    return 0;
}