//
//  main.c
//  AVLTree
//
//  Created by 김영후 on 2015. 2. 3..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "BinarySearchTree.h"
#include "BTreeTraverse.h"

int main(int argc, const char * argv[]) {
  BTreeNode * btNode;
  btNode = MakeBTreeNode();
  BSTMakeAndInit(&btNode);
  
  BSTInsert(&btNode, 1);
  BSTInsert(&btNode, 5);
  BSTInsert(&btNode, 10);
  BSTInsert(&btNode, 2);
  BSTInsert(&btNode, 3);
  
  BTreeInfixTraverse(btNode);
  
  return 0;
}
