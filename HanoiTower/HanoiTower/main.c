//
//  main.c
//  HanoiTower
//
//  Created by 김영후 on 2014. 12. 26..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to) {
  if (num == 1) {
    printf("원반 1을 %c에서 %c로 이동 \n", from, to);
  } else {
    HanoiTowerMove(num-1, from, to, by);
    printf("원반 %d를 %c에서 %c로 이동\n", num, from, to);
    HanoiTowerMove(num-1, by, from, to);
  }
}

int main(int argc, const char * argv[]) {
  HanoiTowerMove(8, 'A', 'B', 'C'); // 4개의 원반을 'A'에서 'C'로 이동시킨다.
  return 0;
}
