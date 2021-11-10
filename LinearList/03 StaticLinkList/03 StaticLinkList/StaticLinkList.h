//
//  StaticLinkList.h
//  03 StaticLinkList
//
//  Created by leung on 2021/11/10.
//

#ifndef StaticLinkList_h
#define StaticLinkList_h

#include <stdio.h>
#include "../../Status/Status/Status.h"

#define MAXSIZE 1000    /*假设链表的最大长度是1000*/
typedef int ElemType;

typedef struct
{
    ElemType data;
    int cur;    /*游标(Cursor), 为0时表示无指向*/
}Component, StaticLinkList[MAXSIZE];

#endif /* StaticLinkList_h */
