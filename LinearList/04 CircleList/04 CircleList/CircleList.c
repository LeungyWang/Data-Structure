//
//  CircleList.c
//  04 CircleList
//
//  Created by leung on 2021/11/29.
//

#include "CircleList.h"

/*************************************************
Function:  InitCircleList
Description:  初始化链式存储结构线性表
Input:
    (CircleList)    *L
Return: (int)   函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status InitCircleList(CircleList *L){
    *L = (CircleList)malloc(sizeof(Node));
    if (!(*L)) {
        return  ERROR;
    }
    (*L)->next = *L;
    return OK;
}

/*************************************************
Function: CircleListIsEmpty
Description: 判断循环链表是否为空
Input:
    (CircleList)    L
Return:(int)    1为为空, 0为不为空
*************************************************/
Status CircleListIsEmpty(CircleList L){
    if (L!=NULL && L->next==L) {
        return TRUE;
    }else{
        return FALSE;
    }
}
