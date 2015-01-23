//
//  BubbleSort.c
//  BubbleSort
//
//  Created by 김영후 on 2015. 1. 23..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "BubbleSort.h"

void BubleSort(int arr[], int n) {
  int i, j;
  int temp;
  
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < (n-i)-1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j] = temp;
      }
    }
  }
}