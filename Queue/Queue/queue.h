//
//  queue.h
//  Queue
//
//  Created by 김영후 on 2015. 1. 14..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __Queue__queue__
#define __Queue__queue__

#include <stdio.h>
#define QUE_LEN 100
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef struct _cQueue {
  int front;
  int rear;
  Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

int NextPosIdx(int pos);

#endif /* defined(__Queue__queue__) */
