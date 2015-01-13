//
//  LinkedRead.c
//  LinkedList
//
//  Created by 김영후 on 2014. 12. 28..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include "LinkedRead.h"
#include <stdio.h>
#include <stdlib.h>

void insertData() {
  int readData;
  Node * newNode;
  
  while (1) { // 노드 추가 루프
    printf("저장할 자연수를 입력해주세요.(0 입력시 종료)");
    scanf("%d", &readData);
    if (readData < 1) {
      break;
    }
    
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = readData;
    newNode->next = NULL;
    
    if (head == NULL) {
      head = newNode;
    } else {
      tail->next = newNode;
    }
    
    tail = newNode;
  }
  return;
}