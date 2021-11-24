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
#include <time.h>
#include "../../../Status/Status/Status.h"

typedef int ElemType;       /*ElemType 类型根据实际情况而定, 这里根据实际情况而定，这里假设为int,**/
typedef int n;
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /*定义LinkList*/

Status InitLinkList(LinkList *L);
Status LinkListInsert(LinkList *L, int i, ElemType e);
Status GetLinkListElem(LinkList L, int i, ElemType *e);
Status LinkListDelete(LinkList *L, int i, ElemType *e);
Status ClearLinkList(LinkList *L);
Status LinkListEmpty(LinkList L);
int LocateLinkListElem(LinkList, ElemType e);
int LinkListLength(LinkList L);
void CreateListHead(LinkList *L, n);
void CreateListTail(LinkList *L, n);
#endif /* LinkList_h */
