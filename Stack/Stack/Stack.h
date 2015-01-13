//
//  Stack.h
//  Stack
//
//  Created by 김영후 on 2015. 1. 1..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __Stack__Stack__
#define __Stack__Stack__

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _stack {
  Data stackArr[STACK_LEN];
  int topOfIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack);

int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);

Data SPop(Stack * pstack);

Data Speek(Stack * pstack);

#endif /* defined(__Stack__Stack__) */
