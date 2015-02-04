//
//  DLinkedList.h
//  DLinkedList
//
//  Created by 김영후 on 2014. 12. 30..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#ifndef __DLinkedList__DLinkedList__
#define __DLinkedList__DLinkedList__

#include <stdio.h>
#include <stdlib.h>
#include "HashFunc_Chaining.h"

#define TRUE  1
#define FALSE 0

// typedef int LData;

typedef struct _node {
  LData data;
  struct _node * next;
} Node;

typedef struct _linkedList {
  Node * head;
  Node * cur;
  Node * before;
  int numOfData;
  int (*comp)(LData d1, LData d2); // 노드 정렬에 필요한 함수 포인터
} LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));

#endif /* defined(__DLinkedList__DLinkedList__) */
