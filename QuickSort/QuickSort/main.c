//
//  main.c
//  QuickSort
//
//  Created by 김영후 on 2015. 1. 26..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "QuickSort.h"

int main(int argc, const char * argv[]) {
  int arr[] = {3, 7, 4, 22, 10, 6, 86, 12};
  int i;
  
  QuickSort(arr, 0, sizeof(arr)/sizeof(int));
  
  for (i = 0; i < sizeof(arr)/sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}
