//
//  HashFunc_Chaining.c
//  HashFunc_Chaining
//
//  Created by 김영후 on 2015. 2. 3..
//  Copyright (c) 2015년 Hoo. All rights reserved.
//

#include "HashFunc_Chaining.h"

void TBLInit(Table * pt, HashFunc * f) {
  int i;
  for (i = 0; i < ARRLEN-1; i++) {
    ListInit(&(pt->tbl[i]));
  }
  pt->hf = f;
};

void TBLInsert(Table * pt, Key k, Value v) {
  int hashValue = pt->hf(k);
  Slot newSlot = {k, v};
  
  if (TBLSearch(pt, k) != NULL) {
    printf("키 중복 오류 발생!! \n");
    return;
  } else {
    LInsert(&(pt->tbl[hashValue]), newSlot);
  }
};

Value TBLDelete(Table * pt, Key k) {
  int hashValue = pt->hf(k);
  Slot cSlot;
  
  if (LFirst(&(pt->tbl[hashValue]), &cSlot)) {
    if (cSlot.key == k) {
      LRemove(&(pt->tbl[hashValue]));
      return cSlot.val;
    } else {
      while (LNext(&(pt->tbl[hashValue]), &cSlot)) {
        if (cSlot.key == k) {
          LRemove(&(pt->tbl[hashValue]));
          return cSlot.val;
        }
      }
    }
  }
  return NULL;
};

Value TBLSearch(Table * pt, Key k) {
  int hashValue = pt->hf(k);
  Slot cSlot;
  
  if (LFirst(&(pt->tbl[hashValue]), &cSlot)) {
    if (cSlot.key == k) {
      return cSlot.val;
    } else {
      while (LNext(&(pt->tbl[hashValue]), &cSlot)) {
        if (cSlot.key == k) {
          return cSlot.val;
        }
      }
    }
  }
  return NULL;
};