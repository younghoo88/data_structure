//
//  BTree.h
//  BTree
//
//  Created by 김영후 on 2015. 1. 20..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __BTree__BTree__
#define __BTree__BTree__

#include <stdio.h>
#include <stdlib.h>

typedef int BTData;

typedef struct _bTreeNode {
  BTData data;
  struct _bTreeNode * left;
  struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);
BTreeNode * GetLeftSubTree(BTreeNode *bt);
BTreeNode * GetRightSubTree(BTreeNode *bt);
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

BTreeNode * RemoveLeftSubTree(BTreeNode * bt);
BTreeNode * RemoveRightSubTree(BTreeNode * bt);
void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);

#endif /* defined(__BTree__BTree__) */
