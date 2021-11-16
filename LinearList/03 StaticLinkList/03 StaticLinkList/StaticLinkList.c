//
//  StaticLinkList.c
//  03 StaticLinkList
//
//  Created by leung on 2021/11/10.
//

#include "StaticLinkList.h"

/*************************************************
Function:  InitStaticLinkList
Description:  初始化静态链表
Input:
    (StaticLinkList)    *L
Return: (int)   函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status InitStaticLinkList(StaticLinkList space)
{
    int i;
    for (i=0; i<MAXSIZE-1; i++) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE-1].cur = 0;   /*目前静态链表为空, 最后一个元素的cur为0*/
}

/*************************************************
Function:  Malloc_SLL
Description: 模拟动态链表的结点申请
Input:
    (StaticLinkList)    space
Return: (int)   分配的结点下标
*************************************************/
int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;   /*当前数组第一个元素的cur存的值*/
                            /*就是要返回的第一个备用空闲的下标*/
    
    if (space[0].cur) {
        space[0].cur = space[i].cur;    /*由于要拿出一个分量来使用了,*/
                                        /*就得把它的下一个分量用来做备用*/
    }
    return i;
}

/*************************************************
Function: StaticLinkListEmpty
Description: 判断静态链表L是否为空
Input:
    (StaticLinkList)    L
Return:(int)    1为为空, 0为不为空
*************************************************/
Status StaticLinkListIsEmpty(StaticLinkList L)
{
    if (L[MAXSIZE-1].cur == 0) {
        return TRUE;
    }else{
        return FALSE;
    }
}

/*************************************************
Function: ClearStaticLinkList
Description: 清空链式结构线性表
Input:
    (StaticLinkList)    *L
Return:(int)    函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status ClearStaticLinkList(StaticLinkList L)
{
    InitStaticLinkList(L);
}

/*************************************************
Function: GeStatictLinkListElem
Description: 获取静态链表中第i个元素, 并赋值到e
Input:
    (StaticLinkList)    L
    (int)           i
    (ElemType)      *e
Return:(int)    函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status GetStaticLinkListElem(StaticLinkList L, int i, ElemType *e)
{
    int j = L[MAXSIZE-1].cur;
    for (int k=1; k<i; k++) {
        j = L[j].cur;
    }
    if (!j) {
        return ERROR;   /*第i个结点不存在*/
    }else{
        *e = L[j].data;
    }
    return OK;
}


/*************************************************
Function: StaticLinkListLength
Description: 返回静态链表中的元素个数
Input:
    (StaticLinkList)    L
Return:(int)    元素个数
**************************************************/
int StaticLinkListLength(StaticLinkList L)
{
    int k;
    k = 0;
    int i = L[MAXSIZE-1].cur;   /*获得第一个结点的位置*/
    while (i) {
        k++;
        i = L[i].cur;
    }
    return k;
}

/*************************************************
Function: StaticLinkListInsert
Description: 在静态链表L中第i个元素之前插入
         新的数据元素e
Input:
    (StaticLinkList)    L
    (Int)           i
    (ElemType)      e
Return:(int)    函数执行状态码,
          1为成功, 0为失败
**************************************************/
Status StaticLinkListInsert(StaticLinkList L, int i, ElemType e)
{
    int j, k, l;
    k = MAXSIZE - 1     /*注意k首先是最后一个元素的下标*/
    if (i < 1 || i > StaticLinkListInsert(L) + 1) {
        return  ERROR;
    }
    j = Malloc_SLL(L);
    if (j) {
        L[j].data = e;
        for (l=1;l<=i-1;l++) {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}

/*************************************************
Function: StaticLinkListDelete
Description: 删除在静态链表中第i个数据元素e
 
Input:
    (StaticLinkList)    L
    (Int)           i
Return:(int)    函数执行状态码,
          1为成功, 0为失败
**************************************************/
Status StaticLinkListDelete(StaticLinkList L, int i)
{
    int j, k;
    if (i < 1 || i > StaticLinkListLength(L)) {
        return  ERROR;
    }
    k = MAXSIZE - 1;
    for (j = 1; j <= i - 1; j++) {
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    return OK;
}

/*************************************************
Function:  Free_SLL
Description: 模拟动态链表的结点释放
Input:
    (StaticLinkList)    space
    (int) k
Return: (int)   分配的结点下标
*************************************************/
void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;    /*把第一个元素cur值赋给要删除的分量cur*/
    space[0].cur = k;   /*把要删除的分量下标赋值给第一个元素的cur*/
}
