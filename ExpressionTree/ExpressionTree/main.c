//
//  main.c
//  ExpressionTree
//
//  Created by 김영후 on 2015. 1. 20..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "ExpressionTree.h"
#include "InfixToPostfix.h"
#include "TreeTraverse.h"

int main(int argc, const char * argv[]) {
  char exp[] = "37+1-3+";
  BTreeNode * expTree = MakeExpTree(exp); // 수식트리의 루트노드 주소값이 저장되어 있다.

  printf("전위 표기법의 수식 : ");
  ShowPrefixTypeExp(expTree);
  printf("\n");
  printf("중위 표기법의 수식 : ");
  ShowInfixTypeExp(expTree);
  printf("\n");
  printf("후위 표기법의 수식 :");
  ShowPostfixTypeExp(expTree);
  printf("\n");
  printf("계산 결과 : ");
  printf("%d \n", EvaluateExpTree(expTree));
  
  return 0;
}
