//
//  HashFunc_Chaining.h
//  HashFunc_Chaining
//
//  Created by 김영후 on 2015. 2. 3..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#ifndef __HashFunc_Chaining__HashFunc_Chaining__
#define __HashFunc_Chaining__HashFunc_Chaining__

#define ARRLEN 15
#define STR_LEN 15

#include <stdio.h>
#include "DLinkedList.h"

typedef struct _person {
  int ssn;
  char name[STR_LEN];
  char addr[STR_LEN];
} Person;

typedef int Key;
typedef Person * Value;

typedef struct _slot {
  Key key;
  Value val;
} Slot;

typedef Slot LData;
typedef int HashFunc(Key k);

typedef struct _table {
  List tbl[ARRLEN];
  HashFunc * hf;
} Table;

void TBLInit(Table * pt, HashFunc * f);
void TBLInsert(Table * pt, Key k, Value v);
Value TBLDelete(Table * pt, Key k);
Value TBLSearch(Table * pt, Key k);


#endif /* defined(__HashFunc_Chaining__HashFunc_Chaining__) */
