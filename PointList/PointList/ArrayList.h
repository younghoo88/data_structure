//
//  ArrayList.h
//  ListMain
//
//  Created by 김영후 on 2014. 12. 27..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#ifndef __ListMain__ArrayList__
#define __ListMain__ArrayList__

#define TRUE  1
#define FALSE 0
#include "Point.h"
#define LIST_LEN 100
typedef Point * LData;

typedef struct __ArrayList {
  LData arr[LIST_LEN]; // 리스트의 저장소인 배열
  int numOfData; // 저장된 데이터의 수
  int curPosition; // 데이터 참조위치를 기록
} ArrayList;

typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

// #include <stdio.h>

#endif /* defined(__ListMain__ArrayList__) */
