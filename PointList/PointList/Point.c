//
//  Point.c
//  PointList
//
//  Created by 김영후 on 2014. 12. 27..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include <stdio.h>
#include "Point.h"

void SetPointPos(Point * ppos, int xpos, int ypos) {
  ppos->xpos = xpos;
  ppos->ypos = ypos;
}

void ShowPointPos(Point * ppos) {
  printf("[xpos : %d, ypos : %d] \n", ppos->xpos, ppos->ypos);
}

int PointComp(Point * pos1, Point * pos2) {
  if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos) {
    return 0; // 멤버값이 모두 같은 경우 0 리턴
  } else if (pos1->xpos == pos2->xpos) {
    return 1;
  } else if (pos1->ypos == pos2->ypos) {
    return 2;
  } else {
    return -1;
  }
}