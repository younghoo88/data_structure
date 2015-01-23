//
//  main.c
//  InsertionSort
//
//  Created by 김영후 on 2015. 1. 23..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "InsertionSort.h"

int main(int argc, const char * argv[]) {
  int i;
  int arr[] = {1, 3, 2, 4};
  
  InsertionSort(arr, sizeof(arr) / sizeof(int));
  for (i = 0; i < 4; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}
