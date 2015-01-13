//
//  main.c
//  ListMain
//
//  Created by 김영후 on 2014. 12. 27..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "ArrayList.h"

int main(int argc, const char * argv[]) {
  List list;
  int data;
  int target = 5;
  ListInit(&list);
  
  LInsert(&list, 1);
  LInsert(&list, 2);
  LInsert(&list, 30);
  LInsert(&list, 5);
  LInsert(&list, 5);
  LInsert(&list, 5);
  LInsert(&list, 8);
  
  printf("- 전체 데이터의 수 : %d \n", LCount(&list));
  
  printf("- 데이터 조회 -\n");
  if (LFirst(&list, &data)) { // 첫번째 데이터 조회
    printf("%d ", data);
    while (LNext(&list, &data)) {
      printf("%d ", data);
    }
  }
  
  printf("\n");
  
  printf("- 데이터 삭제 - \n");
  if (LFirst(&list, &data)) {
    if (data == target) { // 숫자 5가 있는 배열을 찾아서 삭제
      LRemove(&list);
      printf("target %d이(가) 제거되었습니다. \n", target);
    }
    while (LNext(&list, &data)) {
      if (data == target) {
        LRemove(&list);
        printf("target %d이(가) 제거되었습니다. \n", target);
      }
    }
  }
  
  printf("- 삭제 후 데이터 조회 - \n");
  printf("남은 데이터의 수 : %d \n", LCount(&list));
  
  if (LFirst(&list, &data)) {
    printf("%d ", data);
    while (LNext(&list, &data)) {
      printf("%d ", data);
    }
  }
  
  printf("\n");
  
  printf("프로그램을 종료합니다.. \n");
  
  return 0;
}
