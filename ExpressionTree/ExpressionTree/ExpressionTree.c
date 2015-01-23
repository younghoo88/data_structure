//
//  ExpressionTree.c
//  ExpressionTree
//
//  Created by 김영후 on 2015. 1. 20..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "ExpressionTree.h"
#include "ctype.h"

/*
 * MakeExpTree
 * 후위표기법으로 전달된 수식을 수식트리로 구성해주는 함수
 */

BTreeNode * MakeExpTree(char exp[]) {
  Stack stack; // 피연산자를 담을 스택
  BTreeNode * pnode;
  int expLen = strlen(exp); // 후위표기법으로 전달된 문자열 매개변수값의 길이
  int i;
  
  // 스택 초기화
  StackInit(&stack);
  
  for (i = 0; i < expLen; i++) {
    pnode = MakeBTreeNode(); // 하나의 노드 생성(pnode값은 iteration 수행 시마다 바뀐다)
    if (isdigit(exp[i])) { // 피연산자인 경우
      SetData(pnode, exp[i]-'0'); // 해당 숫자를 노드에 저장
    } else { // 연산자인 경우
      MakeRightSubTree(pnode, SPop(&stack)); // 스택에 저장된 숫자를 해당 노드의 오른쪽 노드로 연결하고,
      MakeLeftSubTree(pnode, SPop(&stack));
      SetData(pnode, exp[i]);
      // 최종적으로 만들어진 수식트리
    }
    // 위의 두가지 경우 모두 pnode를 스택에 저장하는 과정을 거친다.
    SPush(&stack, pnode);
  }
  return SPop(&stack);
}


int EvaluateExpTree(BTreeNode * bt) {
  
  if (bt->left == NULL && bt->right == NULL) {
    return GetData(bt);
  }
  
  int op1 = EvaluateExpTree(GetLeftSubTree(bt));
  int op2 = EvaluateExpTree(GetRightSubTree(bt));
  
  switch (GetData(bt)) {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
  }
  return 0;
}