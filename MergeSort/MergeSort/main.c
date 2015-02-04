//
//  main.c
//  MergeSort
//
//  Created by 김영후 on 2015. 1. 23..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "MergeSort.h"

int main(int argc, const char * argv[]) {
  int i;
  int arr[] = {3, 2, 8, 10, 21, 13, 45, 54, 23, 77, 65, 94, 30, 50, 101, 324, 285, 392};
  MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);
  
  printf("Merge Sorting 결과...");
  for (i = 0; i < sizeof(arr)/sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
