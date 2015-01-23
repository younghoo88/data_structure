//
//  LinkedListBasedQueue.h
//  LinkedListQueue
//
//  Created by 김영후 on 2015. 1. 14..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __LinkedListQueue__LinkedListBasedQueue__
#define __LinkedListQueue__LinkedListBasedQueue__

#include <stdio.h>
#include <stdlib.h>
#define QUE_LEN 100
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
  Data data;
  struct _node * next;
} Node;

typedef struct _lQueue {
  Node * front;
  Node * rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif /* defined(__LinkedListQueue__LinkedListBasedQueue__) */
