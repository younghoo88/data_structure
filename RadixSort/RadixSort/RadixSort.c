//
//  RadixSort.c
//  RadixSort
//
//  Created by 김영후 on 2015. 1. 27..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "RadixSort.h"

void RadixSort(int arr[], int num, int maxLen) {
  Queue buckets[BUCKET_NUM];
  int bi;
  int pos;
  int di;
  int divfac = 1;
  int radix;
  
  // Initialize
  for (bi = 0; bi < BUCKET_NUM; bi++) {
    QueueInit(&buckets[bi]);
  }
  
  /*
   * maxLen : 비교할 숫자의 최대 자릿수
   * ex) 1234, 12, 123을 비교한다면 최대 자릿수는 4이다.
   * num : 비교할 숫자의 갯수
   */
  for (pos = 0; pos < maxLen; pos++) {
    // Enqueue
    for (di = 0; di < num; di++) {
      radix = arr[di] / divfac % 10;
      Enqueue(&buckets[radix], arr[di]);
    }
    // Dequeue
    for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {
      while (!QIsEmpty(&buckets[bi])) {
        arr[di++] = Dequeue(&buckets[bi]);
      }
    }
    divfac *= 10;
  }
};