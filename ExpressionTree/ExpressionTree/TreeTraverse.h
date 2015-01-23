//
//  TreeTraverse.h
//  ExpressionTree
//
//  Created by 김영후 on 2015. 1. 20..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __ExpressionTree__TreeTraverse__
#define __ExpressionTree__TreeTraverse__

#include <stdio.h>
#include "BTree.h"

typedef void actionPtr(BTData data);

void showData(int data);

void removeData(BTreeNode * bt);

void InOrderTraverse(BTreeNode * bt, actionPtr action);

void PreOrderTraverse(BTreeNode * bt, actionPtr action);

void PostOrderTraverse(BTreeNode * bt, actionPtr action);

void ShowPrefixTypeExp(BTreeNode * bt);

void ShowPostfixTypeExp(BTreeNode * bt);

void ShowInfixTypeExp(BTreeNode * bt);

#endif /* defined(__ExpressionTree__TreeTraverse__) */
