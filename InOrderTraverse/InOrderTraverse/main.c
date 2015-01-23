//
//  main.c
//  InOrderTraverse
//
//  Created by 김영후 on 2015. 1. 20..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "BTree.h"

/*
 * InorderTraverse
 *
 * Step 1. 왼쪽 서브 트리의 순회
 * Step 2. 루트 노드의 방문
 * Step 3. 오른쪽 서브 트리의 순회
 */

void InorderTraverse(BTreeNode * bt) {
  if (bt == NULL) {
    return;
  }
  InorderTraverse(bt->left);
  printf("%d \n", bt->data);
  InorderTraverse(bt->right);
}

int main(int argc, const char * argv[]) {
  // BTreeNode 생성
  BTreeNode * bt1 = MakeBTreeNode();
  BTreeNode * bt2 = MakeBTreeNode();
  BTreeNode * bt3 = MakeBTreeNode();
  BTreeNode * bt4 = MakeBTreeNode();
  
  // 데이터 입력
  SetData(bt1, 1);
  SetData(bt2, 2);
  SetData(bt3, 3);
  SetData(bt4, 4);
  
  // BTreeNode 연결
  MakeLeftSubTree(bt1, bt2);
  MakeRightSubTree(bt1, bt3);
  MakeLeftSubTree(bt2, bt4);
  
  InorderTraverse(bt1);
  return 0;
}