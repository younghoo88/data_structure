//
//  queue.c
//  Queue
//
//  Created by 김영후 on 2015. 1. 14..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "queue.h"

/*
 * QueueInit
 * 초기 큐는 비어있는 상태이므로 front와 rear는 인덱스 0값을 가지고 있다.
 */

void QueueInit(Queue * pq) {
  pq->front = 0;
  pq->rear = 0;
};

int QIsEmpty(Queue * pq) {
  if (pq->front == pq->rear) {
    return TRUE;
  } else {
    return FALSE;
  }
};

void Enqueue(Queue * pq, Data data) {
  if (NextPosIdx(pq->rear) == pq->front) {
    printf("Queue Memory Error!");
    exit(-1);
  }
  
  pq->rear = NextPosIdx(pq->rear); // rear의 인덱스를 하나 추가함
  pq->queArr[pq->rear] = data;
};

Data Dequeue(Queue * pq) {
  int retData;
  if (QIsEmpty(pq)) {
    printf("Queue Memory Error!");
    exit(-1);
  }
  
  pq->front = NextPosIdx(pq->front);
  retData = pq->queArr[pq->front];
  return retData;
};

Data QPeek(Queue * pq) {
  int retData;
  retData = pq->queArr[pq->front];
  return retData;
};

int NextPosIdx(int pos) {
  if (pos == QUE_LEN-1) {
    return 0;
  } else {
    return pos + 1;
  }
}