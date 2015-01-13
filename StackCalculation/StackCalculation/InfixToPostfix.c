//
//  InfixToPostfix.c
//  StackCalculation
//
//  Created by 김영후 on 2015. 1. 13..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "InfixToPostfix.h"

int getOpPrec(char op) {
  switch (op) {
    case '*':
    case '/':
      return 5;
    case '+':
    case '-':
      return 3;
    case '(':
      return 1;
  }
  return -1; // 등록되지 않은 연산자임을 알림
}

int whoPrecOp(char op1, char op2) {
  int op1Prec = getOpPrec(op1);
  int op2Prec = getOpPrec(op2);
  
  if (op1Prec > op2Prec) {
    return 1; // op1의 우선순위가 더 높은 경우
  } else if (op1Prec < op2Prec) {
    return -1; // op2의 우선순위가 더 높은 경우
  } else {
    return 0; // op1과 op2의 우선순위가 같은 경우
  }
}

/*
 * RPN : Reverse Polish Notation
 * 함수설명 :
 * isdigit(char) : ctype.h 헤더파일에 정의된 함수로, 전달된 문자의 내용이 10진수라면 1을 반환한다.
 */

void convToRPNExp(char * exp) {
  Stack stack;
  int i;
  int idx = 0;
  int expLen = strlen(exp);
  char * convExp = (char*)malloc(expLen+1); // NULL문자를 포함한 변환된 문자열을 넣을 배열
  char tok, popOp;
  
  memset(convExp, 0, sizeof(char)*expLen+1); // 할당된 배열을 0으로 초기화
  StackInit(&stack);
  
  for (i = 0; i < expLen; i++) {
    tok = exp[i]; // exp로 전달된 수식을 한 문자씩 tok에 저장
    if (isdigit(tok)) { // tok에 저장된 문자가 숫자인지 확인
      convExp[idx++] = tok; // 숫자이면 배열 convExp에 그냥 저장
    } else { // 숫자가 아니라면(연산자라면)
      switch (tok) {
        case '(': // 여는 소괄호라면,
          SPush(&stack, tok);
          break;
        case ')': // 닫는 소괄호라면,
          while (1) {
            popOp = SPop(&stack); // 스택에서 연산자를 꺼내어,
            if (popOp == '(') { // 연산자 ( 을 만날때까지,
              break;
            }
            convExp[idx++] = popOp; // 배열 convExp에 저장한다.(idx는 한개씩 증가)
          }
          break;
        case '+': case '-':
        case '*': case '/':
          while (!SIsEmpty(&stack) && whoPrecOp(SPeek(&stack), tok) >= 0) {
            convExp[idx++] = SPop(&stack);
          }
          SPush(&stack, tok);
          break;
      }
    }
  }
  
  // 이제 모든 피연산자(숫자)가 convExp에 이동했다면, 스택에 남아있는 연산자들을 차례대로 꺼내어
  // 저장만 하면 완료가 된다.
  while (!SIsEmpty(&stack)) {
    convExp[idx++] = SPop(&stack);
  }
  
  strcpy(exp, convExp); // 변환된 수식을 매개변수로 넘겨받은 기존 exp에 복사하고
  free(convExp); // 동적할당한 convExp는 메모리해제를 한다.
}