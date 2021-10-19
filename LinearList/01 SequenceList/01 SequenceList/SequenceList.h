//
//  SequenceList.h
//  01 SequenceList
//
//  Created by leung on 2021/10/17.
//

#ifndef SequenceList_h
#define SequenceList_h

#include <stdio.h>
#include <stdlib.h>
#include "../../Status/Status/Status.h"

#define MAXSIZE 20          /*存储空间初始分配量**/

typedef int ElemType;       /*ElemType 类型根据实际情况而定, 这里根据实际情况而定，这里假设为int,**/
typedef struct {
    ElemType data[MAXSIZE];     /*数组存储数据元素, 最大值为MAXSIZE**/
    int length;     /*线性表当前长度**/
}SqList;


Status InitList(SqList *L);
Status ListEmpty(SqList L);
Status GetElem(SqList L, int i, ElemType *e);

#endif /* SequenceList_h */
