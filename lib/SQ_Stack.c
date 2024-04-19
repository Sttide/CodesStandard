#include <stdio.h>
#include <stdlib.h>

#include "basetype.h"
#include "SQ_Stack.h"

STACK_S *StackInit()
{
    STACK_S *pstStack = NULL;

    pstStack = (STACK_S*)malloc(sizeof(STACK_S));
    if (NULL == pstStack)
    {
        return NULL;
    }
    pstStack->base = (int *)malloc(sizeof(int)*STACK_INIT_SIZE);
    if (NULL == pstStack->base)
    {
        return NULL;
    }
    pstStack->top = pstStack->base;
    pstStack->iRealLen = 0;
    pstStack->iInitSize = STACK_INIT_SIZE;

    return pstStack;
}

void StackDestroy (STACK_S *pstStack)
{
    int i = 0;
    for (i = pstStack->iInitSize; i>0; i--)
    {
        free(&pstStack->base[i-1]);
    }
    free(pstStack);
    return;
}

void StackClear (STACK_S *pstStack)
{
    int i = 0;
    for (i = pstStack->iInitSize; i>0; i--)
    {
        pstStack->base[i-1] = 0;
    }
    return;
}

unsigned long StackEmpty (STACK_S *pstStack)
{
    if (pstStack->base == pstStack->top)
    {
        return BOOL_TRUE;
    }
    return BOOL_FALSE;
}

int StackLength (STACK_S *pstStack)
{
    return pstStack->iRealLen;
}

int * StackGetTop (STACK_S *pstStack)
{
    if (pstStack->base == pstStack->top)
    {
        return NULL;
    }
    return pstStack->top;
}

void StackPush (STACK_S *pstStack, int iData)
{
    pstStack->top++;
    *pstStack->top = iData;
    pstStack->iRealLen++;
    return;
}

void StackPop (STACK_S *pstStack)
{
    if (pstStack->base == pstStack->top)
    {
        return;
    }
    pstStack->top--;
    pstStack->iRealLen--;
    return;
}

