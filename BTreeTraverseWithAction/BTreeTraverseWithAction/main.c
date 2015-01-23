//
//  main.c
//  BTreeTraverseWithAction
//
//  Created by 김영후 on 2015. 1. 20..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

/*
 * actionPtr
 * 해당 트리에서 어떤 작업(조회, 삭제)을 할것인지에 대해
 * 함수포인터를 선언해놓음
 */
typedef void actionPtr(BTData data);

void showData(int data) {
  printf("저장된 데이터 : %d \n", data);
}

void removeData(BTreeNode * bt) {
  if (bt == NULL) {
    return;
  }
  
  removeData(bt->left);
  removeData(bt->right);
  
  printf("트리에 저장된 데이터 %d 가(이) 삭제됩니다.\n", bt->data);
  free(bt);
}

void InOrderTraverse(BTreeNode * bt, actionPtr action) {
  if (bt == NULL) {
    return;
  }
  InOrderTraverse(bt->left, action);
  action(bt->data);
  InOrderTraverse(bt->right, action);
}

void PreOrderTraverse(BTreeNode * bt, actionPtr action) {
  if (bt == NULL) {
    return;
  }
  PreOrderTraverse(bt->left, action);
  action(bt->data);
  PreOrderTraverse(bt->right, action);
}

void PostOrderTraverse(BTreeNode * bt, actionPtr action) {
  if (bt == NULL) {
    return;
  }
  PostOrderTraverse(bt->left, action);
  PostOrderTraverse(bt->right, action);
  action(bt->data);
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
  
  // InorderTraverse(bt4, removeData);
  removeData(bt2);
  InOrderTraverse(bt3, showData);
  
  return 0;
}
