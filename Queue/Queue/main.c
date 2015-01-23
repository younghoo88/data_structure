//
//  main.c
//  Queue
//
//  Created by 김영후 on 2015. 1. 14..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

/*
 * Array based Queue
 */

#include <stdio.h>
#include "queue.h"

int main(int argc, const char * argv[]) {
  // Queue의 생성 및 초기화
  Queue queue;
  QueueInit(&queue);
  
  // 데이터 삽입
  Enqueue(&queue, 1);
  Enqueue(&queue, 2);
  Enqueue(&queue, 3);
  Enqueue(&queue, 4);
  Enqueue(&queue, 5);
  
  // 데이터 꺼내기
  while (!QIsEmpty(&queue)) {
    printf("output data : %d \n", Dequeue(&queue));
  }

  return 0;
}