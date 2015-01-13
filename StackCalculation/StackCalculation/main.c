//
//  main.c
//  StackCalculation
//  Infix to Postfix converter
//
//  Created by 김영후 on 2015. 1. 10..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int main(int argc, const char * argv[]) {
  
  //char exp1[] = "3-2+4";
  char exp2[] = "(1+2)*3";
  //char exp3[] = "((1-2)+3*(5-2))";
  //printf("중위표기법 : %s \n", exp1);
  printf("중위표기법 : %s \n", exp2);
  //printf("중위표기법 : %s \n", exp3);
  
  //convToRPNExp(exp1);
  convToRPNExp(exp2); // 중위표기법을 후위표기법으로 변환
  //convToRPNExp(exp3);

  printf("변환 완료!! \n");
  //printf("후위표기법 : %s \n", exp1);
  printf("후위표기법 : %s \n", exp2);
  //printf("후위표기법 : %s \n", exp3);

  printf("후위표기법으로 표현된 수식을 계산!! \n");
  printf("계산 결과 : %d \n",   EvalRPNExp(exp2));
  
  return 0;
}
