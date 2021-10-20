//
//  SequenceList.c
//  01 SequenceList
//
//  Created by leung on 2021/10/17.
//

#include "SequenceList.h"

/*************************************************
Function:  InitList
Description:  初始化顺序存储结构线性表
Input:
    (SqList)    *L
Return: (boolean)   函数执行状态码,
              1为成功, 0为失败
*************************************************/
Status InitList(SqList *L){
    (*L).length = 0;
    return OK;
}

/*************************************************
Function: ListEmpty
Description: 判断顺序存储结构线性表是否为空
Input:
    (SqList)    L
Return:(boolean)    函数执行状态码,
              1为为空, 0为不为空
*************************************************/
Status ListEmpty(SqList L){
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}

/*************************************************
Function: ClearList
Description: 清空顺序结构线性表
Input:
    (SqList)    L
Return:(boolean)    函数执行状态码,
              1为成功, 0为失败
*************************************************/

Status ClearList(SqList *L)
{
    (*L).length = 0;
    return  OK;
}

/*************************************************
Function: GetElem
Description: 获取顺序结构线性表中的元素, 并赋值到e
Input:
    (SqList)    L
    (int)           i
    (ElemType)      *e
Return:(boolean)    函数执行状态码,
              1为成功, 0为失败
*************************************************/
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i-1];
    return  OK;
}

/*************************************************
Function: LocateElem
Description: 获取顺序结构线性表中第一个与元素
         e相同的元素位置, 元素位置从1开始
Input:
    (SqList)    L
    (ElemType)      e
Return:(boolean)    元素e在线性表中的位置，
              不存在即返回0
*************************************************/
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0 ; i < L.length; i++) {
        if (L.data[i] == e)
            return i+1;
    }
    return  0;
}

/*************************************************
Function: ListInsert
Description: 在线性表L中的第i个位置插入新元素e.
Input:
    (SqList)    *L
    (Int)           i
    (ElemType)      e
Return:(boolean)    函数执行状态码,
              1为成功, 0为失败
**************************************************/
Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if (L->length==MAXSIZE) {
        return  ERROR;  /*顺序线性表已满*/
    }
    if (i < 1 || i > L->length+1) { /*当i不在范围内*/
        return  ERROR;
    }
    if (i<=L->length) { /*若插入的位置不在表尾*/
        for (k=L->length-1; k>=i-1; k--) {
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;   /*新元素插入*/
    L->length++;
    return  OK;
}
