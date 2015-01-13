//
//  main.c
//  StackCalculation
//  Infix to Postfix converter
//
//  Created by 김영후 on 2015. 1. 10..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "InfixCalculator.h"

int main(int argc, const char * argv[]) {
  
  char exp1[] = "3-2+4";
  char exp2[] = "(1+2)*3";
  char exp3[] = "((1-2)+3*(5-2))";
  
  printf("1st problem : %s = %d \n", exp1, EvalInfixExp(exp1));
  printf("2nd problem : %s = %d \n", exp2, EvalInfixExp(exp2));
  printf("3rd problem : %s = %d \n", exp3, EvalInfixExp(exp3));
  
  return 0;
}
