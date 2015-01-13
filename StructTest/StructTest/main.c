//
//  main.c
//  StructTest
//
//  Created by 김영후 on 2014. 12. 27..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _point {
  int xpos;
  int ypos;
} Point;

int main(int argc, const char * argv[]) {
  Point * ppos;
  ppos = (Point *)malloc(sizeof(Point));
  ppos->xpos = 1;
  ppos->ypos = 2;
  
  printf("[%d %d]", ppos->xpos, ppos->ypos);
  
  return 0;
}
