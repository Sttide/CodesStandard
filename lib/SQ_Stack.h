/*--------------------------------------------------
            SQ_STACK.H
     author: sttide
       date: 2024/04/18  
description:
----------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
#endif

#define STACK_INIT_SIZE 100

typedef struct SQ_Stack
{
    int *base;
    int *top;
    int iRealLen;
    int iInitSize;
}STACK_S;



STACK_S *StackInit();
void StackDestroy (STACK_S *pstStack);
void StackClear (STACK_S *pstStack);
unsigned long StackEmpty (STACK_S *pstStack);
int StackLength (STACK_S *pstStack);
int * StackGetTop (STACK_S *pstStack);
void StackPush (STACK_S *pstStack, int iData);
void StackPop (STACK_S *pstStack);



#ifdef __cplusplus
}
#endif