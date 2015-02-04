//
//  MergeSort.c
//  MergeSort
//
//  Created by 김영후 on 2015. 1. 23..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "MergeSort.h"

void MergeSort(int arr[], int left, int right) {
  int mid;
  
  if (left < right) { // left가 더 작다는 것은 더 나눌 수 있다는 의미
    mid = (left + right) / 2;
    
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);
    
    // 정렬된 두 배열을 병합한다.
    MergeTwoArea(arr, left, mid, right);
  }
}

/*
 * MergeTwoArea
 * 병합 함수
 * sortArr이라는 배열을 할당하여 정렬한 뒤, 기존 배열에 복사하는 방식인데
 * right기준으로 동적할당되므로, left...값이 크다면 활용되지 않는 메모리가
 * 많아서 낭비이지 않나 싶다.
 */

void MergeTwoArea(int arr[], int left, int mid, int right) {
  // 변수 선언 및 초기화
  int i;
  int lIdx = left;
  int rIdx = mid+1;
  int sIdx = lIdx;
  int * sortArr = (int*)malloc(sizeof(int)*(right+1));
  
  // 1차 병합
  while (lIdx <= mid && rIdx <= right) {
    if (arr[lIdx] <= arr[rIdx]) {
      sortArr[sIdx] = arr[lIdx++];
    } else {
      sortArr[sIdx] = arr[rIdx++];
    }
    sIdx++;
  }
  
  // 1차 병합 후 한쪽 배열이 먼저 완료된 경우 나머지 배열에 남아있던 값들을 sortArr에 담는다.
  if (lIdx > mid) { // 왼쪽 배열이 먼저 완료된 경우
    for (i = rIdx; i <= right; i++, sIdx++) {
      sortArr[sIdx] = arr[i];
    }
  } else {
    for (i = lIdx; i <= mid; i++, sIdx++) {
      sortArr[sIdx] = arr[i];
    }
  }
  
  // sortArr에 최종적으로 정렬된 결과를 원래 배열인 arr에 복사한다.
  for (i = left; i <= right; i++) {
    arr[i] = sortArr[i];
  }
  free(sortArr);
};