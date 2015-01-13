//
//  InfixCalculator.c
//  StackCalculation
//
//  Created by 김영후 on 2015. 1. 13..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "InfixCalculator.h"

int EvalInfixExp(char * exp) {
  int len = strlen(exp);
  int ret;
  char * expcpy = (char *)malloc(len);
  strcpy(expcpy, exp);
  
  convToRPNExp(expcpy);
  ret = EvalRPNExp(expcpy);
  
  free(expcpy);
  return ret;
}