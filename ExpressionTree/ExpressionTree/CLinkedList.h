//
//  CLinkedList.h
//  StackUsingLinkedList
//
//  Created by 김영후 on 2015. 1. 4..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __StackUsingLinkedList__CLinkedList__
#define __StackUsingLinkedList__CLinkedList__

#include <stdio.h>
#include "BTree.h"

#define TRUE 1
#define FALSE 0

//typedef int Data;
typedef BTreeNode * Data;

typedef struct _node {
  Data data;
  struct _node * next;
} Node;

typedef struct _CLL {
  Node * tail;
  Node * cur;
  Node * before;
  
  int numOfData;
} CList;

typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);
void LInsertFront(List * plist, Data data);

int LFirst(List * plist, Data * data);
int LNext(List * plist, Data * data);
Data LRemove(List * plist);
int LCount(List * plist);

#endif /* defined(__StackUsingLinkedList__CLinkedList__) */
