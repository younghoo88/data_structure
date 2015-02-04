//
//  QuickSort.c
//  QuickSort
//
//  Created by 김영후 on 2015. 1. 26..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "QuickSort.h"

void Swap(int arr[], int left, int right);

void QuickSort(int arr[], int left, int right) {
  if (left <= right) {
    int pivot = Partition(arr, left, right);
    QuickSort(arr, left, pivot-1);
    QuickSort(arr, pivot+1, right);
  }
}

int Partition(int arr[], int left, int right) {
  // initialize variables
  int pivot = arr[left];
  int low = left+1;
  int high = right;
  
  while (low <= high) {
    while (pivot >= arr[low] && low <= right) {
      low++;
    }
    
    while (pivot <= arr[high] && high >= (left+1)) {
      high--;
    }
    
    if (low <= high) {
      Swap(arr, low, high);
    }
    
  }
  
  Swap(arr, left, high);
  return high;
};

void Swap(int arr[], int left, int right) {
  int temp;
  temp = arr[left];
  arr[left] = arr[right];
  arr[right] = temp;
}