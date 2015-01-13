//
//  main.c
//  DBLinkedList
//
//  Created by 김영후 on 2014. 12. 31..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "DBLinkedList.h"

int main(int argc, const char * argv[]) {
  List list;
  int inputData;
  int data;
  
  printf("/** List 초기화 **/ \n");
  ListInit(&list);
  
  printf("/** List 데이터 입력 **/ \n");
  while (1) {
    printf("노드에 저장할 자연수를 입력해주세요. \n");
    scanf("%d", &inputData);
    if (inputData != 0) {
      LInsert(&list, inputData);
    } else {
      printf("0이 입력되어 데이터 입력을 종료합니다. \n");
      break;
    }
  }
  
  printf("저장된 전체 데이터 수는 %d개 입니다. \n", LCount(&list));
  
  printf("/** List 데이터 조회(순방향) **/ \n");
  if (LFirst(&list, &data)) {
    printf("%d \n", data);
    while (LNext(&list, &data)) {
      printf("%d \n", data);
    }
    printf("조회 완료...\n");
  } else {
    printf("노드에 저장된 데이터가 없습니다. \n");
    return 0;
  }
  
  printf("/** 데이터 삭제 **/ \n");
  if (LFirst(&list, &data)) {
    if (data == 22) {
      printf("해당 노드의 데이터 %d 을(를) 제거합니다. \n", LRemove(&list));
    }
    while (LNext(&list, &data)) {
      if (data == 22) {
        printf("해당 노드의 데이터 %d 을(를) 제거합니다. \n", LRemove(&list));
      }
    }
  }
  
  printf("/** List 데이터 조회(역방향) **/ \n");
  while (LPrevious(&list, &data)) {
    printf("%d \n", data);
  }
  printf("조회 완료... \n");
  
  return 0;
}
