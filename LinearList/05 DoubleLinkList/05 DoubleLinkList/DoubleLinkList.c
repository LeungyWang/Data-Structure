//
//  DoubleLinkList.c
//  05 DoubleLinkList
//
//  Created by leung on 2022/1/9.
//

#include "DoubleLinkList.h"

/*************************************************
Function:  InitDoubleLinkList
Description:  初始化双向链表
Input:
    (DoubleLinkList)    *L
Return: (int)   函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status InitDoubleLinkList(DuLinkList *L){
    *L = (DuLinkList)malloc(sizeof(DuNode));
    if (!(*L)) {
        return  ERROR;
    }
    (*L)->prior = *L;
    (*L)->next = *L;
    return OK;
}

/*************************************************
Function: DoubleLinkListIsEmpty
Description: 判断双向链表是否为空
Input:
    (DuLinkList)    L
Return:(int)    1为为空, 0为不为空
*************************************************/
Status DoubleLinkListIsEmpty(DuLinkList L){
    if (L!=NULL && L->prior==L && L->next==L) {
        return TRUE;
    }else{
        return FALSE;
    }
}

/*************************************************
Function: ClearDoubleLinkList
Description: 清空双向链表
Input:
    (DuLinkList)    *L
Return:(int)    函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status ClearDoubleLinkList(DuLinkList *L){
    DuLinkList p, q;
    p = (*L)->next;     /*p指向头结点*/
    while (p!=(*L)) {         /*没到表尾*/
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->prior = *L;
    (*L)->next = *L;
    return OK;
}

/*************************************************
Function: GetDoubleLinkListElem
Description: 获取循环链表中第i个元素, 并赋值到e
Input:
    (DuLinkList)    L
    (int)           i
    (ElemType)      *e
Return:(int)    函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status GetDoubleLinkListElem(DuLinkList L, int i, ElemType *e){
    int j;
    DuLinkList p;     /*声明一指针p*/
    p = L->next;    /*让p指向链表含有元素的第一个结点*/
    j = 1;          /*j为计数器*/
    while (p->next!=L && j < i) {
        p = p->next;
        ++j;
    }
    if (i > j) {
        return ERROR;   /*第i个结点不存在*/
    }
    *e = p->data;   /*取第i个结点的数据*/
    return  OK;
}

/*************************************************
Function: LocateDoubleLinkListElem
Description: 获取双向链表中第一个与元素
         e相同的元素位置, 元素位置从1开始
Input:
    (DuLinkList)    L
    (ElemType)      e
Return:(int)    元素e在双向链表中的位置，
              不存在即返回0
*************************************************/
int LocateDoubleLinkListElem(DuLinkList L, ElemType e)
{
    int j;
    DuLinkList p;
    p = L->next;
    j = 0;
    if (p==L) {  // 链表不存在结点
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

/*************************************************
Function: DoubleLinkListInsert
Description: 在循环链表L中的第i个位置插入新元素e.
Input:
    (DuLinkList)    *L
    (Int)           i
    (ElemType)      e
Return:(int)    函数执行状态码,
          1为成功, 0为失败
**************************************************/
Status DoubleLinkListInsert(DuLinkList *L, int i, ElemType e)
{
    int j;
    DuLinkList p,s;
    p = *L;
    j = 0;
    while (p->next!=*L && j < i - 1) {    /*遍历寻找第i-1个结点*/
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;  /*第i个结点不存在*/
    }
    s = (DuLinkList)malloc(sizeof(DuNode)); /*生成新结点(C标准函数)*/
    s->data = e;
    s->prior = p;       /*把p赋值给s的前驱*/
    s->next = p->next;  /*将p的后继结点赋值给s的后继*/
    p->next->prior = s; /*将s赋值给p的后继结点的前驱*/
    p->next = s;    /*将s赋值给p的后继*/
    return  OK;
}

/*************************************************
Function: DoubleLinkListDelete
Description: 删除循环链表中的第i个结点, 并用e返回其值，
         L的长度减1.
Input:
    (DuLinkList)    *L
    (Int)           i
    (ElemType)      *e
Return:(int)    函数执行状态码,
          1为成功, 0为失败
**************************************************/
Status DoubleLinkListDelete(DuLinkList *L, int i, ElemType *e)
{
    int j;
    DuLinkList p, q;
    p = (*L); /*获取头结点*/
    j = 0;
    while (p->next!=*L && j < i - 1) {  /*遍历寻找第i-1个结点*/
        p = p->next;
        j++;
    }
    if (p->next==(*L) || j > i) {
        return ERROR;           /*第i个结点不存在*/
    }
    q = p->next;
    q->prior->next = q->next;   /*将q->next赋值给p->prior的后继*/
    q->next->prior = q->prior;  /*将q->prior赋值给p->next的前驱*/
    *e = q->data;       /*将q结点中的数据给e*/
    free(q);            /*让系统回收此结点, 释放内存*/
    return OK;
}

/*************************************************
Function: DoubleLinkListLength
Description: 返回循环链表L中的元素个数
Input:
    (DuLinkList)    L
Return:(int)    元素个数
**************************************************/
int DoubleLinkListLength(DuLinkList L)
{
    int i;
    DuLinkList p;
    p = L;
    i = 0;
    while (p->next!=L) {
        i++;
        p = p->next;
    }
    return i;
}
