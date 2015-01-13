//
//  main.c
//  DLinkedList
//
//  Created by 김영후 on 2014. 12. 30..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2) {
  if (d1 < d2) {
    return 0;
  } else {
    return -1;
  }
}

int main(void) {
  List list;
  int data;
  ListInit(&list);
  
  SetSortRule(&list, WhoIsPrecede);
  LInsert(&list, 11);
  LInsert(&list, 22);
  LInsert(&list, 33);
  
  printf("현재 데이터의 수 : %d \n", LCount(&list));
  
  if (LFirst(&list, &data)) {
    printf("%d ", data);
    
    while (LNext(&list, &data)) {
      printf("%d ", data);
    }
  }
  
  printf("\n\n");
  
  if (LFirst(&list, &data)) {
    if (data == 22) {
      LRemove(&list);
    }
    
    while (LNext(&list, &data)) {
      if (data == 22) {
        LRemove(&list);
      }
    }
  }

  printf("현재 데이터의 수 : %d \n", LCount(&list));
  
  if (LFirst(&list, &data)) {
    printf("%d ", data);
    
    while (LNext(&list, &data)) {
      printf("%d ", data);
    }
  }
  
  printf("\n\n");
  return 0;
}