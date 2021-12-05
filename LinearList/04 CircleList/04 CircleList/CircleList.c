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

/*************************************************
Function: ClearCircleList
Description: 清空循环链表
Input:
    (CircleList)    *L
Return:(int)    函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status ClearCircleList(CircleList *L){
    CircleList p, q;
    p = (*L)->next;     /*p指向头结点*/
    while (p!=(*L)) {         /*没到表尾*/
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = *L;  /*头结点指针域为头结点*/
    return OK;
}

/*************************************************
Function: GetLinkListElem
Description: 获取循环链表中第i个元素, 并赋值到e
Input:
    (CircleList)    L
    (int)           i
    (ElemType)      *e
Return:(int)    函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status GetCircleListElem(CircleList L, int i, ElemType *e){
    int j;
    CircleList p;     /*声明一指针p*/
    p = L->next;    /*让p指向链表的头结点*/
    j = 1;          /*j为计数器*/
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p) {
        return ERROR;   /*第i个结点不存在*/
    }
    *e = p->data;   /*取第i个结点的数据*/
    return  OK
}

/*************************************************
Function: LocateCircleListElem
Description: 获取循环链表中第一个与元素
         e相同的元素位置, 元素位置从1开始
Input:
    (CircileList)    L
    (ElemType)      e
Return:(int)    元素e在循环链表中的位置，
              不存在即返回0
*************************************************/
int LocateCircleListElem(CircleList L, ElemType e)
{
    int j;
    CircleList p;
    p = L->next;
    j = 0;
    if (p==NULL) {  // 链表不存在结点
        return ERROR;
    }
    while (p!=L) {
        j++;
        if (p->data == e) {
            return j;
        }
        p=p->next;
    }
    // 链表中不存在元素e 返回ERROR
    return  ERROR;
}
