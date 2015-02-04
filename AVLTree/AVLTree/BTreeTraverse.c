//
//  BTreeTraverse.c
//  AVLTree
//
//  Created by 김영후 on 2015. 2. 3..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "BTreeTraverse.h"

void BTreeInfixTraverse(BTreeNode * btNode) {
  
  if (btNode == NULL) { // 재귀함수를 사용하는 경우 항상 탈출조건을 생각하자.
    return;
  }
  // root node가 중간에 출력된다.
  BTreeInfixTraverse(btNode->left);
  printf("output : %d \n", GetData(btNode));
  BTreeInfixTraverse(btNode->right);
}

void BTreePrefixTraverse(BTreeNode * btNode) {
  if (btNode == NULL) {
    return;
  }
  
  printf("output : %d \n", GetData(btNode));
  BTreeInfixTraverse(btNode->left);
  BTreeInfixTraverse(btNode->right);
};

void BTreePostfixTreverse(BTreeNode * btNode) {
  if (btNode == NULL) {
    return;
  }
  
  BTreeInfixTraverse(btNode->left);
  BTreeInfixTraverse(btNode->right);
  printf("output : %d \n", GetData(btNode));
};