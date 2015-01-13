//
//  LinkedRead.h
//  LinkedList
//
//  Created by 김영후 on 2014. 12. 28..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#ifndef __LinkedList__LinkedRead__
#define __LinkedList__LinkedRead__

#include <stdio.h>

typedef struct _node {
  int data;
  struct _node * next;
} Node;

Node * head = NULL;
Node * tail = NULL;
Node * cur = NULL;

void insertData();

#endif /* defined(__LinkedList__LinkedRead__) */
