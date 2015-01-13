//
//  main.c
//  LinkedList
//
//  Created by 김영후 on 2014. 12. 28..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int data;
  struct _node * next;
} Node;

Node * head = NULL;
Node * tail = NULL;
Node * cur = NULL;

Node * deleteNode = NULL;
Node * deleteNextNode = NULL;

int main(int argc, const char * argv[]) {
  int readData;
  Node * newNode;

  /*
   * List 생성
   */
  
  while (1) { // 노드 추가 루프
    printf("저장할 자연수를 입력해주세요.(0 입력시 종료) : ");
    scanf("%d", &readData);
    if (readData < 1) {
      printf("0이 입력되어 저장을 종료합니다.\n");
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
  
  /*
   * List 조회
   */
  if (head == NULL) {
    printf("저장된 노드가 존재하지 않습니다.\n");
    return 0;
  } else {
    cur = head;
    printf("저장된 값 : %d \n", cur->data);
    while (cur->next != NULL) {
      cur = cur->next;
      printf("저장된 값 : %d \n", cur->data);
    }
  }
  
  /*
   * 리스트 삭제
   */
  deleteNode = head; // 첫번째 dn에 head가 가리키는 노드의 주소를 저장한다
  deleteNextNode = deleteNode->next; // 삭제하려는 노드의 next가 가리키는 노드의 주소를 dnn에 저장한다.
  printf("데이터 %d가 저장되어있는 노드가 삭제됩니다. \n",deleteNode->data);
  free(deleteNode); // 지우려는 노드의 메모리를 해제한다.
  printf("삭제 완료 !! \n");

  while (deleteNextNode != NULL) {
    deleteNode = deleteNextNode;
    deleteNextNode = deleteNextNode->next;
    printf("데이터 %d가 저장되어있는 노드가 삭제됩니다. \n",deleteNode->data);
    free(deleteNode);
    printf("삭제 완료 !! \n");
  }
  
  // 모든 노드가 제거되었으니 head와 tail을 NULL로 초기화합니다.
  head = NULL;
  tail = NULL;
  
  /*
   * 리스트 조회
   */
  if (head == NULL) {
    printf("저장된 노드가 존재하지 않습니다. \n");
    return 0;
  } else {
    cur = head;
    printf("저장된 값 : %d \n", cur->data);
    while (cur->next != NULL) {
      cur = cur->next;
      printf("저장된 값 : %d \n", cur->data);
    }
  }

  return 0;
}
