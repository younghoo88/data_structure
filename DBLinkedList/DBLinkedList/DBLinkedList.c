//
//  DBLinkedList.c
//  DBLinkedList
//
//  Created by 김영후 on 2014. 12. 31..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include "DBLinkedList.h"
#include <stdlib.h>

void ListInit(List * plist) {
  plist->head = (Node *)malloc(sizeof(Node));
  plist->tail = (Node *)malloc(sizeof(Node));
  
  plist->head->prev = NULL;
  plist->head->next = plist->tail;
  
  plist->tail->next = NULL;
  plist->tail->prev = plist->head;
  
  plist->numOfData = 0;
}

void LInsert(List * plist, Data data) {
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  
  newNode->prev = plist->tail->prev;
  plist->tail->prev->next = newNode;
  
  newNode->next = plist->tail;
  plist->tail->prev = newNode;
  
  (plist->numOfData)++;
}

int LFirst(List * plist, Data * data) {
  if (plist->head->next == plist->tail) {
    return FALSE;
  }
  plist->cur = plist->head->next;
  *data = plist->cur->data; // 첫번째 노드에 저장된 data를 data(input param)에 저장
  return TRUE;
}

int LNext(List * plist, Data * data) {
  if (plist->cur->next == plist->tail) {
    return FALSE;
  }
  plist->cur = plist->cur->next; // 다음 노드로 cursor를 이동
  *data = plist->cur->data;
  return TRUE;
}

int LPrevious(List * plist, Data * data) {
  if (plist->cur->prev == NULL) {
    return FALSE;
  }
  *data = plist->cur->data;
  plist->cur = plist->cur->prev; // 이전 노드로 cursor를 이동
  return TRUE;
}

Data LRemove(List * plist) {
  Node * rpos;
  Data rData;
  
  rpos = plist->cur;
  rData = rpos->data;
  
  plist->cur->prev->next = plist->cur->next;
  plist->cur->next->prev = plist->cur->prev;
  
  plist->cur = plist->cur->prev;
  free(rpos);
  return rData;
}

int LCount(List * plist) {
  return plist->numOfData;
}