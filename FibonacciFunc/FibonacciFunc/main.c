//
//  main.c
//  FibonacciFunc
//
//  Created by 김영후 on 2014. 12. 26..
//  Copyright (c) 2014년 Hoo. All rights reserved.
//

#include <stdio.h>

int fibo(int n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else {
    return fibo(n-1) + fibo(n-2);
  }
}

int main(int argc, const char * argv[]) {
  int i;
  for (i = 1; i < 15; i++) {
    printf("%d ", fibo(i));
  }
  
  return 0;
}
