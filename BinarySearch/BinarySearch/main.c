//
//  main.c
//  BinarySearch
//
//  Created by 김영후 on 2014. 12. 25..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include <stdio.h>

int BSearch(int ar[], int len, int target) {
  int first = 0;
  int last = len-1;
  int mid;
  
  while (first <= last) {
    mid = (first + last) / 2;
    
    if (target == ar[mid]) {
      return mid;
    } else {
      if (target < ar[mid]) {
        last = mid - 1;
      } else {
        first = mid + 1;
      }
    }
  }
  
  printf("first index : %d, last index : %d \n", first, last);
  
  return -1;
}

int main(int argc, const char * argv[]) {
  int arr[] = {1, 3, 5, 7, 9};
  int idx;
  int targetNum = 7;
  
  idx = BSearch(arr, sizeof(arr)/sizeof(int), targetNum);
  
  if (idx == -1) {
    printf("Searching is failed \n");
  } else {
    printf("Searching target index is %d \n", idx);
  }
  
  return 0;
}
