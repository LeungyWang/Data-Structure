//
//  main.c
//  02 LinkList
//
//  Created by leung on 2021/10/26.
//

#include <stdio.h>
#include "LinkList.h"

int main(int argc, const char * argv[]) {
    LinkList L;
    int i;
    int ret;
    ElemType e;

    printf("\n**********01-InitLinkList-TEST-BEGIN************\n");     //  01.函数InitLinkList测试
    {
        printf("\n开始初始化链式结构线性表L\n");
        ret = InitLinkList(&L);
        if (ret == OK) {
            printf("\n链式结构线性表L初始化成功\n");
        }else{
            printf("\n链式结构线性表L初始化化失败\n");
        }
        
    }
    printf("\n***********01-InitLinkList-TEST-END***********\n\n");

    printf("\n***********02-LinkListInsert-TEST-BEGIN***********\n");     // 02.函数LinkListInsert测试
    {
        e = 77;
        // 在线性表第一个位置插入元素
        i = 1;
        ret = LinkListInsert(&L, i, e);
        if (ret == OK) {
            printf("\n链式结构线性表L插入元素%d到位置%d, 成功\n", e, i);
        }else{
            printf("\n链式结构线性表L插入元素%d到位置%d, 失败\n", e, i);
        }
        
    }
    printf("\n***********02-LinkListInsert-TEST-END***********\n\n");

    printf("\n***********03-GetLinkListElem-TEST-BEGIN***********\n");     // 04.函数GetLinkListElem测试
    {
        ret = GetLinkListElem(L, i, &e);
        if (ret == ERROR) {
            printf("\n获取链式结构线性表L第%d个元素,失败\n", i);
        }else {
            printf("\n获取链式结构线性表L第%d个元素成功, 元素为%d\n", i, e);
        }
        
    }
    printf("\n***********03-GetLinkListElem-TEST-END***********\n\n");

    printf("\n***********04-LocateLinkListElem-TEST-BEGIN***********\n");     // 04.函数LocateLinkListElem测试
    {
        ret = LocateLinkListElem(L, e);
        if (ret == ERROR) {
            printf("\n获取元素%d在链式结构线性表L中的位置, 失败\n", e);
        }else {
            printf("\n获取元素%d在链式结构线性表L中的位置成功, 位置为%d\n", e, ret);
        }
        
    }
    printf("\n***********04-LocateLinkListElem-TEST-END***********\n\n");

    printf("\n***********05-LinkListLength-TEST-BEGIN***********\n");     // 05.函数LinkListLength测试
    {
        ret = LinkListLength(L);
        printf("\n链式结构线性表L长度为%d\n\n", ret);
    }
    printf("\n***********05-LinkListLength-TEST-END***********\n\n");

    printf("\n***********06-LinkListDelete-TEST-BEGIN***********\n");     // 06.函数LinkListDelete测试
    {
        ret = LinkListDelete(&L, i, &e);
        if (ret == ERROR) {
            printf("\n链式结构线性表删除位置%d元素失败",i);
        }else{
            printf("\n删除线性表L位置%d元素成功, 元素为%d\n", i, e);
        }
    }
    printf("\n***********06-LinkListDelete-TEST-END***********\n\n");

    
    printf("\n***********07-ClearLinkList-TEST-BEGIN***********\n");     // 07.函数ClearLinkList测试
    {
        ret = ClearLinkList(&L);
        if (ret == OK) {
            printf("\n清空链式结构线性表L成功\n");
        }
    }
    printf("\n***********07-ClearLinkList-TEST-END***********\n\n");

    printf("\n***********08-LinkListEmpty-TEST-BEGIN***********\n");     // 08.函数LinkListEmpty测试
    {
        int empty = LinkListEmpty(L);
        if (empty) {
            printf("\n线性表为空\n");
        }else{
                printf("\n线性表不为空");
        }
    }
    printf("\n***********08-LinkListEmpty-TEST-END***********\n\n");
    
    printf("\n***********09-CreateListHead-TEST-BEGIN***********\n");     // 09.函数CreateListHead测试
    {
        int n;
        n = 10;
        CreateListHead(&L, n);  // 产生10个随机数, 插入L
        for (int i=1; i<=n; i++) {
            GetLinkListElem(L, i, &e);
            printf("\n链式结构线性表第%d个元素为%d",i,e);
        }
        ClearLinkList(&L);
        
    }
    printf("\n***********09-CreateListHead-TEST-END***********\n\n");
    
    printf("\n***********10-CreateListTail-TEST-BEGIN***********\n");     // 10.函数CreateListTail测试
    {
        int n;
        n = 10;
        CreateListTail(&L, n);  // 产生10个随机数, 插入L
        for (int i=1; i<=n; i++) {
            GetLinkListElem(L, i, &e);
            printf("\n链式结构线性表第%d个元素为%d",i,e);
        }
        ClearLinkList(&L);
        
    }
    printf("\n***********10-CreateListTail-TEST-END***********\n\n");
}


