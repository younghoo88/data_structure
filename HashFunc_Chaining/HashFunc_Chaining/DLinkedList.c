//
//  DLinkedList.c
//  DLinkedList
//
//  Created by 김영후 on 2014. 12. 30..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include "DLinkedList.h"

/**
 * List Data Structure의 ADT(Abstract Data Type)
 */

void FInsert(List * plist, LData data);
void SInsert(List * plist, LData data);

/**
 * ListInit
 * 초기화할 리스트의 주소값을 인자로 전달한다.
 * 리스트 생성 후 제일 먼저 호출되어야 하는 함수이다.
 */
void ListInit(List * plist) {
  plist->head = (Node *)malloc(sizeof(Node));
  plist->head->next = NULL;
  plist->comp = NULL;
  plist->numOfData = 0;
}

/**
 * LInsert
 * 리스트에 데이터를 저장한다. 매개변수 data에 전달된 값을 노드에 저장한다.
 */
void LInsert(List * plist, LData data) {
  if (plist->comp == NULL) { // 정렬 기준이 마련되지 않은 경우
    FInsert(plist, data);
  } else {
    SInsert(plist, data);
  }
}

/**
 * FInsert
 * 헤더파일에 정의되지 않은 함수
 */
void FInsert(List * plist, LData data) {
  Node * newNode = (Node *)malloc(sizeof(Node)); // 새 노드 생성
  newNode->data = data; // 새 노드에 데이터 저장
  newNode->next = plist->head->next; // newNode가 dummy node가 가리키던 node를 가리키게 함
  plist->head->next = newNode; // dummy node가 newNode를 가리키게 함
  
  (plist->numOfData)++; // 전체 노드의 수 하나 증가
}

void SInsert(List *plist, LData data) {
  Node * newNode = (Node *)malloc(sizeof(Node));
  Node * pred = plist->head;
  
  newNode->data = data;
  
  // 새 노드가 들어갈 위치를 찾기 위한 반복문
  while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
    pred = pred->next;
  }
  
  newNode->next = pred->next;
  pred->next = newNode;
  
  (plist->numOfData)++;
}

/**
 * List의 조회
 * LFirst와 LNext로 나뉜다.
 */

int LFirst(List * plist, LData * pdata) {
  if (plist->head->next == NULL) {
    return FALSE;
  }
  plist->before = plist->head;
  plist->cur = plist->head->next;
  
  *pdata = plist->cur->data;
  return TRUE;
}

int LNext(List * plist, LData * pdata) {
  if (plist->cur->next == NULL) {
    return FALSE;
  }
  plist->before = plist->cur;
  plist->cur = plist->cur->next;
  *pdata = plist->cur->data;
  return TRUE;
}

LData LRemove(List * plist) {
  Node * rpos = plist->cur; // 삭제될 노드의 주소값을 rpos에 저장
  LData rdata = rpos->data; // 삭제될 노드에 담겨진 데이터

  plist->before->next = plist->cur->next;
  plist->cur = plist->before;
  
  free(rpos);
  (plist->numOfData)--;
  return rdata;
}

int LCount(List * plist) {
  return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2)) {
  plist->comp = comp;
};