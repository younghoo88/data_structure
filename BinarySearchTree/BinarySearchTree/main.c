//
//  main.c
//  BinarySearchTree
//
//  Created by 김영후 on 2015. 1. 28..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "BinarySearchTree.h"

int main(int argc, const char * argv[]) {
  BTreeNode * bstRoot;
  BTreeNode * sNode; // search node
  
  BSTMakeAndInit(&bstRoot);
  
  BSTInsert(&bstRoot, 9);
  BSTInsert(&bstRoot, 1);
  BSTInsert(&bstRoot, 6);
  BSTInsert(&bstRoot, 2);
  BSTInsert(&bstRoot, 8);
  BSTInsert(&bstRoot, 3);
  BSTInsert(&bstRoot, 5);
  
  sNode = BSTSearch(bstRoot, 1);
  if (sNode == NULL) {
    printf("탐색 실패!!\n");
  } else {
    printf("탐색에 성공한 키의 값 : %d \n", BSTGetNodeData(sNode));
  }
  
  sNode = BSTSearch(bstRoot, 10);
  if (sNode == NULL) {
    printf("탐색 실패!!\n");
  } else {
    printf("탐색에 성공한 키의 값 : %d \n", BSTGetNodeData(sNode));
  }
  
  return 0;
}
