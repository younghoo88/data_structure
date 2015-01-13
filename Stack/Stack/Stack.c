//
//  Stack.c
//  Stack
//
//  Created by 김영후 on 2015. 1. 1..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack * pstack) {
  pstack->topOfIndex = -1;
};

int SIsEmpty(Stack * pstack) {
  if (pstack->topOfIndex == -1) {
    return TRUE;
  } else {
    return FALSE;
  }
};

void SPush(Stack * pstack, Data data) {
  (pstack->topOfIndex)++; // topOfIndex의 index를 하나 추가하고,
  pstack->stackArr[pstack->topOfIndex] = data; // 해당 topOfIndex에 data를 추가한다.
};

Data SPop(Stack * pstack) {
  Data pData;
  if (SIsEmpty(pstack)) {
    printf("Stack Memory Error !");
    exit(-1);
  } else {
    pData = pstack->stackArr[pstack->topOfIndex];
    (pstack->topOfIndex)--;
  }
  return pData;
};

Data Speek(Stack * pstack) {
  Data pData;
  if (SIsEmpty(pstack)) {
    printf("Stack Memory Error !");
    exit(-1);
  } else {
    pData = pstack->stackArr[pstack->topOfIndex];
  }
  return pData;
};