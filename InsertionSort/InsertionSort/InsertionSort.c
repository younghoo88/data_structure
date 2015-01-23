//
//  InsertionSort.c
//  InsertionSort
//
//  Created by 김영후 on 2015. 1. 23..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "InsertionSort.h"

void InsertionSort(int arr[], int n) {
  int i, j;
  int temp;
  for (i = 1; i < n; i++) {
    temp = arr[i];
    for (j = i-1; j>=0; j--) {
      if (arr[j] > temp) {
        arr[j+1] = arr[j];
      } else {
        break;
      }
    }
    arr[j+1] = temp;
  }
}