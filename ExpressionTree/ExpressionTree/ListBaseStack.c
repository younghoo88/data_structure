//
//  ListBaseStack.c
//  StackUsingLinkedList
//
//  Created by 김영후 on 2015. 1. 4..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "ListBaseStack.h"

void StackInit(Stack * pstack) {
  pstack->plist = (List *)malloc(sizeof(List));
  ListInit(pstack->plist);
}

int SIsEmpty(Stack * pstack) {
  if (!LCount(pstack->plist)){
    return TRUE;
  } else {
    return FALSE;
  }
}

void SPush(Stack * pstack, Data data) {
  LInsertFront(pstack->plist, data);
}

Data SPop(Stack * pstack) {
  Data data;
  LFirst(pstack->plist, &data);
  LRemove(pstack->plist);
  return data;
}

Data SPeek(Stack * pstack) {
  Data data;
  LFirst(pstack->plist, &data);
  return data;
}