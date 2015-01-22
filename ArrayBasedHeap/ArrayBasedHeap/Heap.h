//
//  Heap.h
//  ArrayBasedHeap
//
//  Created by 김영후 on 2015. 1. 21..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __ArrayBasedHeap__Heap__
#define __ArrayBasedHeap__Heap__
#define TRUE 1
#define FALSE 0
#define HEAP_LEN 255

#include <stdio.h>

typedef char HData;
typedef int Priority;

typedef struct _heapElem {
  Priority pr; // 데이터 우선순위(낮을수록 높은 우선순위를 가짐)
  HData data;
} HeapElem;

typedef struct _heap {
  int numOfData;
  HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph);
int HIsEmpty(Heap * ph);

int GetLChildIdx(int idx);
int GetRChildIdx(int idx);
int GetParentIdx(int idx);
int GetHiPriChildIdx(Heap * ph, int idx);

void HInsert(Heap * ph, HData data, Priority pr);
HData HDelete(Heap * ph);

#endif /* defined(__ArrayBasedHeap__Heap__) */
