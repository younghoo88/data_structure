//
//  main.c
//  Stack
//
//  Created by 김영후 on 2015. 1. 1..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "Stack.h"

int main(int argc, const char * argv[]) {
  Stack stack;
  StackInit(&stack);
  
  SPush(&stack, 11);
  SPush(&stack, 22);
  SPush(&stack, 33);
  SPush(&stack, 44);
  SPush(&stack, 55);
  
  while (!SIsEmpty(&stack)) {
    printf("%d ",SPop(&stack));
  }
  
  return 0;
}