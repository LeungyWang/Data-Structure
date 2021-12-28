//
//  main.c
//  04 CircleList
//
//  Created by leung on 2021/11/24.
//

#include <stdio.h>
#include "CircleList.h"

int main(int argc, const char * argv[]) {
    CircleList L;
    int i;
    int ret;
    ElemType e;

    
    printf("\n**********01-InitCircleList-TEST-BEGIN************\n");     //  01.函数InitCircleList测试
    {
        printf("\n开始初始化循环链表L\n");
        ret = InitCircleList(&L);
        if (ret == OK) {
            printf("\n循环链表L初始化成功\n");
        }else{
            printf("\n循环链表L初始化化失败\n");
        }
    }
    printf("\n***********01-InitCircleList-TEST-END***********\n\n");
    
    printf("\n***********02-CircleListInsert-TEST-BEGIN***********\n");     // 02.函数CircleListInsert测试
    {
        e = 77;
        // 在循环链表第一个位置插入元素
        i = 1;
        ret = CircleListInsert(&L, i, e);
        i = 2;
        e = 7;
        ret = CircleListInsert(&L, i, e);
        if (ret == OK) {
            printf("\n循环链表L插入元素%d到位置%d, 成功\n", e, i);
        }else{
            printf("\n循环链表L插入元素%d到位置%d, 失败\n", e, i);
        }
        
    }
    printf("\n***********02-CircleListInsert-TEST-END***********\n\n");
    
    printf("\n***********03-GetCircleListElem-TEST-BEGIN***********\n");     // 03.函数GetCircleListElem测试
    {
        ret = GetCircleListElem(L, i, &e);
        if (ret == ERROR) {
            printf("\n获取循环链表第%d个元素,失败\n", i);
        }else {
            printf("\n获取循环链表L第%d个元素成功, 元素为%d\n", i, e);
        }
        
    }
    printf("\n***********03-GetCircleListElem-TEST-END***********\n\n");

    printf("\n***********04-LocateCircleListElem-TEST-BEGIN***********\n");     // 04.函数LocateCircleListElem测试
    {
        ret = LocateCircleListElem(L, e);
        if (ret == ERROR) {
            printf("\n获取元素%d在链式结构线性表L中的位置, 失败\n", e);
        }else {
            printf("\n获取元素%d在链式结构线性表L中的位置成功, 位置为%d\n", e, ret);
        }

    }
    printf("\n***********04-LocateCircleListElem-TEST-END***********\n\n");

    printf("\n***********05-CircleListLength-TEST-BEGIN***********\n");     // 05.函数CircleListLength测试
    {
        ret = CircleListLength(L);
        printf("\n链式结构线性表L长度为%d\n\n", ret);
    }
    printf("\n***********05-CircleListLength-TEST-END***********\n\n");

    printf("\n***********06-CircleListDelete-TEST-BEGIN***********\n");     // 06.函数CircleListDelete测试
    {
        i = 2;
        ret = CircleListDelete(&L, i, &e);
        if (ret == ERROR) {
            printf("\n链式结构线性表删除位置%d元素失败",i);
        }else{
            printf("\n删除线性表L位置%d元素成功, 元素为%d\n", i, e);
        }
    }
    printf("\n***********06-CircleListDelete-TEST-END***********\n\n");
    
    return 0;
    
}
