//
//  main.c
//  RadixSort
//
//  Created by 김영후 on 2015. 1. 27..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "RadixSort.h"

int main(int argc, const char * argv[]) {
  int i;
  int arr[] = {13, 212, 14, 7141, 10987, 6, 15};
  int len = sizeof(arr)/sizeof(int);
  RadixSort(arr, len, 5);
  
  for (i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}