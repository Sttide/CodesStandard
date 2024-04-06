#include <stdio.h>
#include <stdlib.h>

typedef unsigned long Status;
#define SQ_INIT_LENGTH 128
#define OK 1
#define ERROR 0

typedef struct SQ_DataNode
{
    int num;
    int age;
    int role;
}SQ_DATANODE_S;

typedef struct SQ_Array
{
    SQ_DATANODE_S *elem;
    int length;
    int listsize;
}SQ_ARRAY_S;

Status SQ_Init(SQ_ARRAY_S *list)
{
    int listsize = sizeof(SQ_DATANODE_S)*SQ_INIT_LENGTH;
    list->elem = (SQ_DATANODE_S *)malloc(sizeof(SQ_DATANODE_S)*SQ_INIT_LENGTH);
    if (NULL == list->elem)
    {
        return ERROR;
    }
    list->length = SQ_INIT_LENGTH;
    list->listsize = listsize;
    return  OK;
}

Status SQ_AddNode(SQ_ARRAY_S *list, int i)
{
    int num, age, role;
    scanf("%d%d%d", &num, &age, &role);
    list->elem[i].num = num;
    list->elem[i].age = age;
    list->elem[i].role = role;
    printf("%d %d %d\r\n", list->elem[i].num, list->elem[i].age, list->elem[i].role);
    return OK;
}

int main()
{
    SQ_ARRAY_S g_Squence;
    int i = 0;
    SQ_Init(&g_Squence);
    for (i = 0; i < 3; i++)
    {
        SQ_AddNode(&g_Squence, i);
    }
    printf("Success!\r\n");
    return 0;
}