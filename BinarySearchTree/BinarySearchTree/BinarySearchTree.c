//
//  BinarySearchTree.c
//  BinarySearchTree
//
//  Created by 김영후 on 2015. 1. 28..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot) {
  *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst) {
  return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data) {
  BTreeNode * pNode = NULL; // parent node
  BTreeNode * cNode = *pRoot; // current node
  BTreeNode * nNode = NULL; // new node
  
  //while문을 수행하면서 새로운 노드가 추가될 위치를 찾는다.(NULL이 나올때까지)
  while (cNode != NULL) {
    if (data == GetData(cNode)) {
      return; // 데이터(키)의 중복을 허용하지 않는다.
    }
    
    pNode = cNode; // current node의 위치를 옮기기 전에 parent node를 저장해둔다.
    
    if (GetData(cNode) > data) {
      cNode = GetLeftSubTree(cNode);
    } else {
      cNode = GetRightSubTree(cNode);
    }
  }
  
  // 추가할 위치를 찾았으니 이제 노드를 생성하여 입력된 data를 추가한다.
  nNode = MakeBTreeNode(); // 새로운 노드의 생성
  SetData(nNode, data); // 새 노드에 데이터 저장
  
  // pNode의 자식노드로 nNode를 추가한다.
  if (pNode != NULL) {
    if (GetData(pNode) > data) {
      MakeLeftSubTree(pNode, nNode);
    } else {
      MakeRightSubTree(pNode, nNode);
    }
  } else { // pNode가 NULL이라면(현재 만든 nNode가 루트노드가 되는 것이라면)
    *pRoot = nNode;
  }
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target) {
  BTreeNode * cNode = bst; // 현재 노드
  BSTData currentData; // 현재 데이터
  
  while (cNode != NULL) {
    currentData = GetData(cNode);
    if (target == currentData) {
      return cNode;
    } else if (target < currentData) {
      cNode = GetLeftSubTree(cNode);
    } else {
      cNode = GetRightSubTree(cNode);
    }
  }
  return NULL; // 탐색 실패(이진 탐색 트리에 target data가 없는 경우 NULL반환)
}

