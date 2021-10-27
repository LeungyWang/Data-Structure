//
//  LinkList.h
//  02 LinkList
//
//  Created by leung on 2021/10/27.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <stdlib.h>
#include "../../Status/Status/Status.h"

typedef int ElemType;       /*ElemType 类型根据实际情况而定, 这里根据实际情况而定，这里假设为int,**/
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /*定义LinkList*/

#endif /* LinkList_h */
