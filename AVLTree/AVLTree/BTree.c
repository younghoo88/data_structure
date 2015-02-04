//
//  BTree.c
//  BTree
//
//  Created by 김영후 on 2015. 1. 20..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "BTree.h"

/*
 * MakeBTreeNode function
 * Binary Tree를 만드는 함수이다.
 * 함수가 호출되면, 힙에 BTreeNode 구조체가 할당되고, 이 구조체의 주소값이 반환된다.
 */
BTreeNode * MakeBTreeNode(void) {
  BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
  nd->left = NULL;
  nd->right = NULL;
  return nd;
}

BTData GetData(BTreeNode * bt) {
  return bt->data;
}

void SetData(BTreeNode * bt, BTData data) {
  bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt) {
  return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt) {
  return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
  if (main->left != NULL) {
    free(main->left);
  }
  main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub) {
  if (main->right != NULL) {
    free(main->right);
  }
  main->right = sub;
}

BTreeNode * RemoveLeftSubTree(BTreeNode * bt) {
  BTreeNode * delNode;
  
  if (bt != NULL) {
    delNode = bt->left;
    bt->left = NULL;
  }
  return delNode;
}

BTreeNode * RemoveRightSubTree(BTreeNode * bt) {
  BTreeNode * delNode;
  
  if (bt != NULL) {
    delNode = bt->right;
    bt->right = NULL;
  }
  return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
  main->left = sub;
}

void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub) {
  main->right = sub;
}