#include <stdio.h>
#include <stdlib.h>

#include "./lib/basetype.h"
#include "./lib/SQ_Stack.h"

int main()
{
    STACK_S *pstStack = NULL;
    pstStack = StackInit();
    StackPush(pstStack, 1);
    StackPush(pstStack, 2);
    StackPush(pstStack, 3);
    StackPush(pstStack, 4);
    StackPush(pstStack, 5);
    printf("%d\r\n", *StackGetTop(pstStack));
    StackPop(pstStack);
    printf("%d\r\n", *StackGetTop(pstStack));
    StackPop(pstStack);
    printf("%d\r\n", *StackGetTop(pstStack));
    StackPop(pstStack);
    printf("%d\r\n", *StackGetTop(pstStack));
    StackPop(pstStack);
    printf("%d\r\n", *StackGetTop(pstStack));
    return 0;
}