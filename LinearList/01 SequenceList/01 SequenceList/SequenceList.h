//
//  SequenceList.h
//  01 SequenceList
//
//  Created by leung on 2021/10/17.
//

#ifndef SequenceList_h
#define SequenceList_h

#include <stdio.h>

#define MAXSIZE 20          /*存储空间初始分配量**/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;       /*ElemType 类型根据实际情况而定, 这里根据实际情况而定，这里假设为int,**/
typedef int Status;

typedef struct {
    ElemType data[MAXSIZE];     /*数组存储数据元素, 最大值为MAXSIZE**/
    int length;     /*线性表当前长度**/
}SqList;

Status GetElem(SqList L, int i, ElemType *e);

#endif /* SequenceList_h */
