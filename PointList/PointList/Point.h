//
//  Point.h
//  PointList
//
//  Created by 김영후 on 2014. 12. 27..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#ifndef __PointList__Point__
#define __PointList__Point__
// #include <stdio.h>

typedef struct _point {
  int xpos;
  int ypos;
} Point;

// Point 변수의 xpos, ypos 값 설정
void SetPointPos(Point * ppos, int xpos, int ypos);

// Point 변수의 xpos, ypos 정보 출력
void ShowPointPos(Point * ppos);

// 두 Point 변수의 비교
int PointComp(Point * pos1, Point * pos2);

#endif /* defined(__PointList__Point__) */
