//
//  ArrayList.c
//  ListMain
//
//  Created by 김영후 on 2014. 12. 27..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include "ArrayList.h"

/*
 * 리스트 초기화
 */

void ListInit(List * plist) {
  plist->numOfData = 0; // 리스트에 저장된 데이터의 수는 0
  plist->curPosition = -1; // 현재 아무 위치도 가리키지 않음
}

/*
 * 데이터 저장
 */

void LInsert(List * plist, LData data) {
  if (plist->numOfData >= LIST_LEN) { // 예외 처리
    puts("배열길이를 초과하여 더이상 저장할 수 없습니다.");
    return;
  }
  
  plist->arr[plist->numOfData] = data; // 데이터 저장
  (plist->numOfData)++; // 저장된 데이터의 수 증가
}

/*
 * 첫 번째 조회
 */

int LFirst(List * plist, LData * pdata) {
  if (plist->numOfData == 0) { // 예외 처리
    return FALSE;
  }
  (plist->curPosition) = 0; // 참조 위치 초기화(첫 번째 데이터의 참조를 의미한다)
  *pdata = plist->arr[0]; // pdata가 가리키는 공간에 데이터 저장
  return TRUE;
}

/*
 * 두 번째 이후의 조회
 */

int LNext(List * plist, LData * pdata) {
  if (plist->curPosition >= plist->numOfData-1) { // 예외 처리
    return FALSE;
  }
  (plist->curPosition)++;
  *pdata = plist->arr[plist->curPosition];
  return TRUE;
}

/*
 * 데이터 삭제
 */
LData LRemove(List * plist) {
  int i;
  int rpos = plist->curPosition;
  int num = plist->numOfData;
  LData removedData = plist->arr[rpos];
  
  for (i = rpos; i < num-1; i++) {
    plist->arr[i] = plist->arr[i+1];
  }
  (plist->numOfData)--;
  (plist->curPosition)--;
  
  return removedData;
}

/*
 * 전체 데이터 개수
 */
int LCount(List * plist) {
  return plist->numOfData;
}