//
//  ExpressionTree.h
//  ExpressionTree
//
//  Created by 김영후 on 2015. 1. 20..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __ExpressionTree__ExpressionTree__
#define __ExpressionTree__ExpressionTree__

#include <stdio.h>
#include "ListBaseStack.h"
#include "BTree.h"

BTreeNode * MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode * bt);

#endif /* defined(__ExpressionTree__ExpressionTree__) */
