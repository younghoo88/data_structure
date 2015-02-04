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

/*
 * BSTRemove함수에서는 삭제할 노드의 자식 노드의 개수에 따라 3가지 경우로 나누어 처리한다.
 *
 * case 1 : 삭제할 노드의 자식 노드가 1개인 경우
 * case 2 : 삭제할 노드의 자식 노드가 2개인 경우
 * case 3 : 삭제할 노드의 자식 노드가 3개인 경우
 *
 * 삭제할 노드가 루트노드(*pRoot)인 경우도 생길 수 있는데, 이 경우는 앞서 3가지 경우로 처리하는
 * 방법으로는 삭제가 어렵다. 따라서 pVRoot라는 가상의 노드를 생성하여 *pRoot를 pVRoot의
 * 오른쪽 자식노드로 간주한다면 3가지 경우 중 하나로 나누어 처리할 수 있기 때문에 이 방법을 사용한다.
 * 물론 pVRoot는 함수 종료시 소멸된다.
 * 다른 노드의 삭제와는 달리 루트노드가 삭제되는 경우 매개변수로 전달된 *pRoot의 값이 바뀌므로
 * 반드시 GetRightSubTree(pVRoot)함수를 호출하여 바뀐 *pRoot의 값으로 치환해주어야 한다.
 */

// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target) {
  /*
   * 초기화
   *
   * pVRoot라는 가상 루트 노드를 가리키는 포인터 변수를 하나 생성한다.
   * parent node인 pNode는 pVRoot로 초기화가 되고, current node인 cNode는
   * 기존에 설정되어 있던 루트 노드로 초기화 된다. 이 두 포인터 변수(pNode, cNode)는
   * 삭제할 대상(dNode)을 탐색하는 과정에서 계속해서 업데이트가 이루어진다.
   */
  BTreeNode * pVRoot = MakeBTreeNode(); // 가상 루트 노드
  BTreeNode * pNode = pVRoot; // parent node
  BTreeNode * cNode = *pRoot; // current node
  BTreeNode * dNode; // delete node
  
  // 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되도록 한다.
  ChangeRightSubTree(pVRoot, *pRoot);
  
  // 삭제 대상인 노드를 탐색한다.
  while (cNode != NULL && GetData(cNode) != target) {
    pNode = cNode; // 삭제 대상 노드의 부모 노드를 백업
    if (target < GetData(cNode)) {
      cNode = GetLeftSubTree(cNode);
    } else {
      cNode = GetRightSubTree(cNode);
    }
  }
  
  if (cNode == NULL) { // 삭제 대상이 존재하지 않는 경우
    return NULL;
  }
  
  // 삭제 대상을 찾은 경우 dNode에 값을 저장한다.
  dNode = cNode;
  
  // 첫 번째 경우 : 삭제 대상이 단말 노드인 경우(자식 노드가 없다.)
  if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
    
    if (GetLeftSubTree(pNode) == dNode) {
      RemoveLeftSubTree(pNode);
    } else {
      RemoveRightSubTree(pNode);
    }

  // 두 번째 경우 : 삭제 대상이 하나의 자식 노드를 갖는 경우
  } else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode)) {
    
    BTreeNode * dcNode; // 삭제 대상의 자식 노드를 가리킴
    
    // 왼쪽 자식 노드가 존재한다면 dcNode에 왼쪽 자식 노드 주소값을 저장,
    // 반대로 오른쪽 자식 노드가 존재한다면 dcNode에 오른쪽 자식 노드의 주소값을 저장한다.
    if (GetLeftSubTree(dNode) != NULL) {
      dcNode = GetLeftSubTree(dNode);
    } else {
      dcNode = GetRightSubTree(dNode);
    }
    
    /*
     * 자식 노드와 부모 노드를 서로 연결한다.
     * 삭제할 노드가 부모 노드의 왼쪽이라면, 자식 노드 또한 부모 노드의 왼쪽에 연결시키고,
     * 오른쪽이라면 오른쪽에 연결시킨다.
     */
    if (GetLeftSubTree(pNode) == dNode) {
      ChangeLeftSubTree(pNode, dcNode);
    } else {
      ChangeRightSubTree(pNode, dcNode);
    }
    
  // 세 번째 경우 : 삭제 대상이 두개의 자식 노드를 갖는 경우
  } else {
    BTreeNode * mNode = GetRightSubTree(dNode); // dNode를 대체할 노드
    BTreeNode * mpNode = dNode;
    int delData;
    
    while (GetLeftSubTree(mNode) != NULL) {
      mpNode = mNode; // 부모 노드 백업
      mNode = GetLeftSubTree(mNode);
    }
    
    delData = GetData(dNode);
    SetData(dNode, GetData(mNode));
    
    if (GetRightSubTree(mNode) != NULL) {
      ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
    }
    
    dNode = mNode;
    SetData(dNode, delData);
  }
  
  // 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
  if (GetRightSubTree(pVRoot) != *pRoot) {
    *pRoot = GetRightSubTree(pVRoot);
  }
  
  free(pVRoot);
  return dNode;
};