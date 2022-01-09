//
//  DoubleLinkList.h
//  05 DoubleLinkList
//
//  Created by leung on 2022/1/9.
//

#ifndef DoubleLinkList_h
#define DoubleLinkList_h

#include <stdio.h>
#include <stdlib.h>
#include "../../../Status/Status/Status.h"


typedef int ElemType;       /*ElemType 类型根据实际情况而定, 这里根据实际情况而定，这里假设为int,**/
typedef struct DuNode{
    ElemType data;
    struct DuNode *prior;
    struct DuNode *next;
}DuNode;
typedef struct DuNode *DuLinkList; /*定义DuLinkList*/

#endif /* DoubleLinkList_h */
