#include <stdio.h>
#include <stdlib.h>

typedef unsigned long Status;
#define SQ_INIT_LENGTH 128
#define OK 1
#define ERROR 0

#define offset(type, member)    \
    ((size_t)(&(((type*)0)->member)))

#define contain_of(ptr, type, member)   \
    (type*)(ptr - (offset(type, member)))

typedef struct stListNode{
    struct stListNode *pNext;
}SIMPLE_LIST_HEAD_S;

typedef struct LNode
{
    SIMPLE_LIST_HEAD_S stList;
    int data1;
    int data2;
    int data3;
}TEST_DATA_NODE_S, TEST_DATA_HEAD_S;

void  SQ_ListPreInput(TEST_DATA_HEAD_S *pList, int n)
{
    SIMPLE_LIST_HEAD_S *pstTmp = NULL; /* loop*/
    TEST_DATA_NODE_S *pstNode = NULL;
    int data;

    pstTmp = &(pList->stList);
    while (n>0)
    {
        scanf("%d", &data);
        pstNode = (TEST_DATA_NODE_S*)malloc(sizeof(TEST_DATA_NODE_S));
        pstNode->data1 = data;
        pstNode->stList.pNext = NULL;
 
        pstTmp->pNext = &(pstNode->stList);
        pstTmp = pstTmp->pNext;
 
        n--;
    }
    return;
}

void  SQ_ListPreOutput(TEST_DATA_HEAD_S *pList)
{
    SIMPLE_LIST_HEAD_S *pstTmp = NULL; /* loop*/
    TEST_DATA_NODE_S *pTmpNode = NULL;

    pstTmp = pList->stList.pNext;
    while (pstTmp != NULL)
    {
        pTmpNode = contain_of(pstTmp, TEST_DATA_NODE_S, stList);  
        printf("%d\r\n", pTmpNode->data1);
        pstTmp = pstTmp->pNext;
    }
    return;
}

void  SQ_ListInit(TEST_DATA_HEAD_S *pList)
{
    pList->stList.pNext = NULL;
    return;
}

int main()
{
    TEST_DATA_HEAD_S g_pList;

    printf("%ld\r\n", sizeof(SIMPLE_LIST_HEAD_S));
    printf("%ld\r\n", offset(TEST_DATA_NODE_S, stList));
    SQ_ListInit(&g_pList);
    SQ_ListPreInput(&g_pList, 3);
    SQ_ListPreOutput(&g_pList);

    return 0;
}