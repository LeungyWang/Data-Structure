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
Return: (boolean)函数执行状态码, 1为成功, 0为失败
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
Return:(boolean)函数执行状态码, 1为为空, 0为不为空
*************************************************/
Status ListEmpty(SqList L){
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}

/*************************************************
Function: GetElem
Description: 获取顺序结构线性表中的元素, 并赋值到e
Input:
    (SqList)    L
    (int)           i
    (ElemType)      *e
Return:(boolean)函数执行状态码, 1为成功, 0为失败
*************************************************/
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i-1];
    return  OK;
}
