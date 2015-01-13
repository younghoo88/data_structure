//
//  main.c
//  StackUsingLinkedList
//
//  Created by 김영후 on 2015. 1. 4..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "ListBaseStack.h"

int main(int argc, const char * argv[]) {
  Stack stack;
  StackInit(&stack);
  
  SPush(&stack, 1);
  SPush(&stack, 3);
  SPush(&stack, 5);
  SPush(&stack, 7);
  SPush(&stack, 9);

  while (!SIsEmpty(&stack)) {
    printf("%d ", SPop(&stack));
  }

  return 0;
}
