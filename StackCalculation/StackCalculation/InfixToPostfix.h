//
//  InfixToPostfix.h
//  StackCalculation
//
//  Created by 김영후 on 2015. 1. 13..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __StackCalculation__InfixToPostfix__
#define __StackCalculation__InfixToPostfix__

int whoPrecOp(char op1, char op2);
int getOpPrec(char op);
void convToRPNExp(char * exp);

#endif /* defined(__StackCalculation__InfixToPostfix__) */
