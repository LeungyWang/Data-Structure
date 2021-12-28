//
//  CircleList.h
//  04 CircleList
//
//  Created by leung on 2021/11/29.
//

#ifndef CircleList_h
#define CircleList_h

#include <stdio.h>
#include <stdlib.h>
#include "../../../Status/Status/Status.h"


typedef int ElemType;       /*ElemType 类型根据实际情况而定, 这里根据实际情况而定，这里假设为int,**/
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *CircleList; /*定义CircleList*/

Status InitCircleList(CircleList *L);
Status CircleListInsert(CircleList *L, int i, ElemType e);
Status GetCircleListElem(CircleList L, int i, ElemType *e);
Status CircleListDelete(CircleList *L, int i, ElemType *e);
Status ClearCircleList(CircleList *L);
Status CircleListEmpty(CircleList L);
int LocateCircleListElem(CircleList, ElemType e);
int CircleListLength(CircleList L);

#endif /* CircleList_h */
