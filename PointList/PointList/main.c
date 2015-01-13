//
//  main.c
//  PointList
//
//  Created by 김영후 on 2014. 12. 27..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(int argc, const char * argv[]) {
  List list;
  Point compPos;
  Point * ppos;
  
  /*
   * 초기화
   */
  ListInit(&list);
  
  /*
   * 데이터 저장
   */

  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 2, 1);
  LInsert(&list, ppos);
  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 3, 10);
  LInsert(&list, ppos);
  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 66, 77);
  LInsert(&list, ppos);
  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 2, 15);
  LInsert(&list, ppos);
  
  printf("전체 데이터 개수 : %d\n", LCount(&list));
  
  /*
   * 데이터 조회
   */
  
  if (LFirst(&list, &ppos)) {
    ShowPointPos(ppos);
    printf("%p\n", ppos); // Heap 영역에 할당된 구조체는 8바이트가 아닌 10바이트가 할당되어 있다.(여분의 메모리)
    while (LNext(&list, &ppos)) {
      ShowPointPos(ppos);
      printf("%p\n", ppos);
    }
  }
  
  printf("\n");
  
  // xpos가 2인 모든 데이터 삭제
  compPos.xpos = 2;
  compPos.ypos = 0;
  
  if (LFirst(&list, &ppos)) {
    if (PointComp(ppos, &compPos) == 1) {
      ppos = LRemove(&list);
      free(ppos);
    }
    while (LNext(&list, &ppos)) {
      if (PointComp(ppos, &compPos) == 1) {
        ppos = LRemove(&list);
        free(ppos);
      }
    }
  }
  
  printf("전체 데이터 개수 : %d\n", LCount(&list));
  
  if (LFirst(&list, &ppos)) {
    ShowPointPos(ppos);
    printf("%p\n", ppos);
    while (LNext(&list, &ppos)) {
      ShowPointPos(ppos);
      printf("%p\n", ppos);
    }
  }
  
  return 0;
}
