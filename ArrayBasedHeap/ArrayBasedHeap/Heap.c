//
//  Heap.c
//  ArrayBasedHeap
//
//  Created by 김영후 on 2015. 1. 21..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "Heap.h"

void HeapInit(Heap * ph) {
  ph->numOfData = 0;
}

int HIsEmpty(Heap * ph) {
  if (ph->numOfData == 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}

int GetLChildIdx(int idx) {
  return idx * 2;
}

int GetRChildIdx(int idx) {
  return GetLChildIdx(idx) + 1;
}

int GetParentIdx(int idx) {
  return idx / 2;
}

/*
 * GetHiPriChildIdx
 * 왼쪽 노드와 오른쪽 노드 중 우선순위가 높은 노드의 인덱스를 반환하는 함수이다.
 * Parent 노드에 연결된 자식 노드의 경우에 따라 반환되는 값이 다르다.
 * Case 1 : 자식 노드가 없는 경우(0 반환)
 * Case 2 : 자식 노드가 하나만 존재하는 경우(해당 자식 노드의 인덱스 반환)
 * Case 3 : 자식 노드가 왼쪽, 오른쪽 모두 존재하는 경우(우선순위 비교 후 인덱스 반환)
 */

int GetHiPriChildIdx(Heap * ph, int idx) {
  
  if (GetLChildIdx(idx) > ph->numOfData) {   // 자식 노드가 없는 경우
    return 0;
  } else if (GetLChildIdx(idx) == ph->numOfData) { // 자식 노드가 하나만 존재하는 경우
    return GetLChildIdx(idx);
  } else {
    if (ph->heapArr[GetLChildIdx(idx)].pr < ph->heapArr[GetRChildIdx(idx)].pr) { // 왼쪽 노드의 우선 순위가 높은 경우
      return GetLChildIdx(idx);
    } else {
      return GetRChildIdx(idx);
    }
  }
}

HData HDelete(Heap * ph) {
  // 최하위 노드 데이터의 저장
  HeapElem lastElem;
  lastElem.data = ph->heapArr[ph->numOfData].data;
  lastElem.pr = ph->heapArr[ph->numOfData].pr;
  
  // 반환을 위한 루트 노드의 데이터 저장
  HData rtnData  = ph->heapArr[1].data;
  
  int parentNode = 1;
  
  while (lastElem.pr > ph->heapArr[GetHiPriChildIdx(ph, parentNode)].pr) {
    ph->heapArr[parentNode] = ph->heapArr[GetHiPriChildIdx(ph, parentNode)];
    parentNode = GetHiPriChildIdx(ph, parentNode);
  }
  
  ph->heapArr[parentNode] = lastElem;
  ph->numOfData--;
  
  return rtnData;
}

void HInsert(Heap * ph, HData data, Priority pr) {
  int idx = ph->numOfData+1; // 새 노드가 저장될 인덱스 값을 idx에 저장
  HeapElem nelem = {pr, data}; // 새 노드의 생성 및 초기화
  
  while (idx != 1) { // 새 노드와 부모 노드의 우선순위 비교
    if (pr < (ph->heapArr[GetParentIdx(idx)].pr)) { // 새 노드의 우선순위가 높다면
      
      ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)]; // 부모 노드를 한 레벨 내림, 실제로 내림
      idx = GetParentIdx(idx); // 새 노드를 한 레벨 올림, 실제로 올리지는 않고 인덱스값만 갱신
      
    } else { // 새 노드의 우선순위가 높지 않다면
      break;
    }
  }
  
  ph->heapArr[idx] = nelem; // 새 노드를 배열에 저장
  ph->numOfData++;
}





