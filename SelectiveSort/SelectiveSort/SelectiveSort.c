//
//  SelectiveSort.c
//  SelectiveSort
//
//  Created by 김영후 on 2015. 1. 23..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "SelectiveSort.h"

void SelSort(int arr[], int n) {
  int i, j;
  int minIdx;
  int temp;
  
  for (i = 0; i < n-1; i++) {
    minIdx = i;
    for (j = i+1; j < n; j++) {
      if (arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[minIdx];
    arr[minIdx] = temp;
  }
}