//
//  main.c
//  SelectiveSort
//
//  Created by 김영후 on 2015. 1. 23..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "SelectiveSort.h"

int main(int argc, const char * argv[]) {
  int i;
  int arr[] = {4, 1, 2, 3};
  
  SelSort(arr, 4);
  for (i = 0; i < 4; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}
