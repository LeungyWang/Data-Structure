//
//  LinkList.c
//  02 LinkList
//
//  Created by leung on 2021/10/27.
//

#include "LinkList.h"

/*************************************************
Function:  InitLinkList
Description:  初始化链式存储结构线性表
Input:
    (LinkList)    *L
Return: (int)   函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status InitLinkList(LinkList *L){
    *L = (LinkList)malloc(sizeof(Node));
    if (!(*L)) {
        return  ERROR;
    }
    (*L)->next = NULL;
    return OK;
}

/*************************************************
Function: LinkListEmpty
Description: 判断顺序存储结构线性表是否为空
Input:
    (LinkList)    L
Return:(int)    1为为空, 0为不为空
*************************************************/
Status LinkListEmpty(LinkList L){
    if (L!=NULL && L->next==NULL) {
        return TRUE;
    }else{
        return FALSE;
    }
}

/*************************************************
Function: ClearLinkList
Description: 清空链式结构线性表
Input:
    (LinkList)    *L
Return:(int)    函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status ClearLinkList(LinkList *L){
    LinkList p, q;
    p = (*L)->next;     /*p指向头结点*/
    while (p) {         /*没到表尾*/
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;  /*头结点指针域为空*/
    return OK;
}

/*************************************************
Function: GetLinkListElem
Description: 获取链式结构线性表中第i个元素, 并赋值到e
Input:
    (LinkList)    L
    (int)           i
    (ElemType)      *e
Return:(int)    函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status GetLinkListElem(LinkList L, int i, ElemType *e){
    int j;
    LinkList p;     /*声明一指针p*/
    p = L->next;    /*让p指向链表的头结点*/
    j = 1;          /*j为计数器*/
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j>i) {
        return ERROR;   /*第i个结点不存在*/
    }
    *e = p->data;   /*取第i个结点的数据*/
    return  OK;
    
}

/*************************************************
Function: LocateLinkListElem
Description: 获取链式结构线性表中第一个与元素
         e相同的元素位置, 元素位置从1开始
Input:
    (LinkList)    L
    (ElemType)      e
Return:(int)    元素e在线性表中的位置，
              不存在即返回0
*************************************************/
int LocateLinkListElem(LinkList L, ElemType e)
{
    int j;
    LinkList p;
    p = L->next;
    j = 0;
    if (p==NULL) {  // 链表不存在结点
        return ERROR;
    }
    while (p!=NULL) {
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
Function: LinkListInsert
Description: 在链式结构线性表L中的第i个位置插入新元素e.
Input:
    (LinkList)    *L
    (Int)           i
    (ElemType)      e
Return:(int)    函数执行状态码,
          1为成功, 0为失败
**************************************************/
Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p,s;
    p = *L;
    j = 1;
    while (p && j < i) {    /*遍历寻找第i-1个结点*/
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return  ERROR;  /*第i个结点不存在*/
    }
    s = (LinkList)malloc(sizeof(Node)); /*生成新结点(C标准函数)*/
    s->data = e;
    s->next = p->next;  /*将p的后继结点赋值给s的后继*/
    p->next = s;    /*将s赋值给p的后继*/
    return  OK;
}

/*************************************************
Function: LinkListDelete
Description: 删除链表L中的第i个结点, 并用e返回其值，
         L的长度减1.
Input:
    (LinklList)    *L
    (Int)           i
    (ElemType)      *e
Return:(int)    函数执行状态码,
          1为成功, 0为失败
**************************************************/
Status LinkListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next && j < i) {  /*遍历寻找第i-1个结点*/
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i) {
        return ERROR;           /*第i个结点不存在*/
    }
    q = p->next;
    p->next = q->next;  /*将q的后继赋值给p的后继*/
    *e = q->data;       /*将q结点中的数据给e*/
    free(q);            /*让系统回收此结点, 释放内存*/
    return OK;
}

/*************************************************
Function: CreateListHead
Description: 随机产生n个元素的值, 建立
         带表头结点的单链线性表L(头插法)
Input:
    (LinklList)    *L
    (Int)           n
**************************************************/
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(0));     /*初始化随机数种子*/
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;  /*先建立一个带头结点的单链表*/
    for (i=0; i<n; i++) {
        p = (LinkList)malloc(sizeof(Node)); /*随机生成100以内的数字*/
        p->data = rand()%100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;     /*插入到表头*/
    }
}

/*************************************************
Function: CreateListTail
Description: 随机产生n个元素的值, 建立
         带表头结点的单链线性表L(尾插法)
Input:
    (LinklList)    *L
    (Int)           n
**************************************************/
void CreateListTail(LinkList *L, int n)
{
    LinkList p, r;
    int i;
    srand(time(0));     /*初始化随机数种子*/
    *L = (LinkList)malloc(sizeof(Node));     /*为整个线性表*/
    r = *L;     /*r为指向尾部的结点*/
    for (i=0; i<n; i++) {
        p = (Node *)malloc(sizeof(Node));   /*生成新结点*/
        p->data = rand()%100 + 1;       /*随机生成100以内的数字*/
        r->next = p;        /*将表尾终端结点的指针指向新结点*/
        r = p;      /*将当前的新结点定义为表尾终端结点*/
    }
    r->next = NULL;     /*表示当前链表结束*/
}


