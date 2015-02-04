//
//  BinarySearchTree.h
//  BinarySearchTree
//
//  Created by 김영후 on 2015. 1. 28..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __BinarySearchTree__BinarySearchTree__
#define __BinarySearchTree__BinarySearchTree__

#include <stdio.h>
#include "BTree.h"

typedef BTData BSTData; // BTData는 현재 int로 정의되어 있다.

// BST의 생성 및 초기화
void BSTMakeAndInit(BTreeNode ** pRoot);

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst);

// BST를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode ** pRoot, BSTData data);

// BST를 대상으로 데이터 탐색
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

// BST를 대상으로 데이터 삭제
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

// BST에 저장된 모든 노드의 데이터를 출력한다.
void BSTShowAll(BTreeNode * bst);

#endif /* defined(__BinarySearchTree__BinarySearchTree__) */
