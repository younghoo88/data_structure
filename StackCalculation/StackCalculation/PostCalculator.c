//
//  PostCalculator.c
//  StackCalculation
//
//  Created by 김영후 on 2015. 1. 13..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "ListBaseStack.h"
#include "PostCalculator.h"
#include "ctype.h"

int EvalRPNExp(char * exp) {
  Stack stack; // 숫자를 담을 스택
  int expLen = strlen(exp);
  int i;
  int tempInt;
  char tempChar;
  char d1, d2;
  StackInit(&stack);
  
  for (i = 0; i < expLen; i++) {
    tempChar = exp[i];
    if (isdigit(tempChar)) { // 숫자라면,
      SPush(&stack, tempChar - '0');
    } else {
      d1 = SPop(&stack);
      d2 = SPop(&stack);
      switch (tempChar) {
        case '+':
          tempInt = d1+d2;
          SPush(&stack, d2 + d1);
          break;
        case '-':
          SPush(&stack, d2 - d1);
          break;
        case '*':
          SPush(&stack, d2 * d1);
          break;
        case '/':
          SPush(&stack, d2 / d1);
          break;
      }
    }
  }
  return SPop(&stack);
}