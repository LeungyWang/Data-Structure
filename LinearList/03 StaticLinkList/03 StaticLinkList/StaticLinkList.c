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
Function: StaticLinkListLength
Description: 返回静态链表中的元素个数
Input:
    (StaticLinkList)    L
Return:(int)    元素个数
**************************************************/
int StaticLinkListLength(StaticLinkList space)
{
    int k;
    k = 0;
    int i = space[MAXSIZE-1].cur;   /*获得第一个结点的位置*/
    while (space[i].cur) {
        k++;
        i = space[i].cur;
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
Status StaticLinkListInsert(StaticLinkList space)
{
    int j, k, l;
    k = MAXSIZE - 1     /*注意k首先是最后一个元素的下标*/
    if (i < 1 || ) {
        <#statements#>
    }
    
    
}

