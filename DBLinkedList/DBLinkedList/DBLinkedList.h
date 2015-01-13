//
//  DBLinkedList.h
//  DBLinkedList
//
//  Created by 김영후 on 2014. 12. 31..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#ifndef __DBLinkedList__DBLinkedList__
#define __DBLinkedList__DBLinkedList__

#include <stdio.h>

#define TRUE 1;
#define FALSE 0;

typedef int Data;

typedef struct _node {
  Data data;
  struct _node * next;
  struct _node * prev;
} Node;

typedef struct _DBLinkedList {
  Node * head;
  Node * tail;
  Node * cur;
  int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * data);
int LNext(List * plist, Data * data);
int LPrevious(List * plist, Data * data);
int LRemove(List * plist);
int LCount(List * plist);

#endif /* defined(__DBLinkedList__DBLinkedList__) */
