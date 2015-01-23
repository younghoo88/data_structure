//
//  LinkedListBasedQueue.c
//  LinkedListQueue
//
//  Created by 김영후 on 2015. 1. 14..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "LinkedListBasedQueue.h"

void QueueInit(Queue * pq) {
  pq->front = NULL;
  pq->rear = NULL;
};

int QIsEmpty(Queue * pq) {
  if (pq->front == NULL) {
    return TRUE;
  } else {
    return FALSE;
  }
};

void Enqueue(Queue * pq, Data data) {
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->data = data;
  
  if (QIsEmpty(pq)) {
    pq->front = newNode;
    pq->rear = newNode;
  } else {
    pq->rear->next = newNode;
    pq->rear = newNode;
  }
};

Data Dequeue(Queue * pq) {
  Data retData;
  Node * delNode;
  
  if (QIsEmpty(pq)) {
    printf("Queue Memory Error!");
    exit(-1);
  }

  delNode = pq->front;
  retData = pq->front->data;
  pq->front = pq->front->next;
  free(delNode);
  
  return retData;
};

// Data QPeek(Queue * pq);