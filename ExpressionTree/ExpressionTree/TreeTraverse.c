//
//  TreeTraverse.c
//  ExpressionTree
//
//  Created by 김영후 on 2015. 1. 20..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "TreeTraverse.h"
#include "ctype.h"

void showData(int data) {
  if (0<=data && data<=9) {
    printf("%d ", data);
  } else {
    printf("%c ", data);
  }
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
  action(bt->data);
  PreOrderTraverse(bt->left, action);
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

void ShowPrefixTypeExp(BTreeNode * bt) {
  PreOrderTraverse(bt, showData);
}

void ShowPostfixTypeExp(BTreeNode * bt) {
  PostOrderTraverse(bt, showData);
}

void ShowInfixTypeExp(BTreeNode * bt) {
  InOrderTraverse(bt, showData);
}
