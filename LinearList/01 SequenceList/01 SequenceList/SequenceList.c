//
//  SequenceList.c
//  01 SequenceList
//
//  Created by leung on 2021/10/17.
//

#include "SequenceList.h"

Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length){
        return ERROR;
    }
    *e = L.data[i-1];
    return  OK;
}
