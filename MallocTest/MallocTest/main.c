//
//  main.c
//  MallocTest
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
  int i;
  Point * ppos;
  ppos = (Point *)malloc(sizeof(Point)*3);
  for (i = 0; i < 3; i++) {
    (ppos+i)->xpos = i;
    (ppos+i)->ypos = i;
  }
  
  for (i = 0; i < 3; i++) {
    printf("[%d %d]\n", (ppos+i)->xpos, (ppos+i)->ypos);
  }
  
  
  return 0;
}
