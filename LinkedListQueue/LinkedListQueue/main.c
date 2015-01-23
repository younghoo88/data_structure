//
//  main.c
//  LinkedListQueue
//
//  Created by 김영후 on 2015. 1. 14..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "LinkedListBasedQueue.h"

int main(int argc, const char * argv[]) {
  Queue queue;
  QueueInit(&queue);
  
  // 데이터 넣기
  Enqueue(&queue, 1);
  Enqueue(&queue, 2);
  Enqueue(&queue, 3);
  Enqueue(&queue, 4);
  Enqueue(&queue, 5);
  
  // 데이터 꺼내기
  while (!QIsEmpty(&queue)) {
    printf("%d ", Dequeue(&queue));
  }
  
  return 0;
}
