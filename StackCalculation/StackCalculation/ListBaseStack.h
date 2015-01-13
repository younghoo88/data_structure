//
//  ListBaseStack.h
//  StackUsingLinkedList
//
//  Created by 김영후 on 2015. 1. 4..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __StackUsingLinkedList__ListBaseStack__
#define __StackUsingLinkedList__ListBaseStack__

#include <stdio.h>
#include "CLinkedList.h"

typedef struct _listStack {
  List * plist;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif /* defined(__StackUsingLinkedList__ListBaseStack__) */
