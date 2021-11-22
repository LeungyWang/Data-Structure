//
//  main.c
//  03 StaticLinkList
//
//  Created by leung on 2021/11/10.
//

#include <stdio.h>
#include "StaticLinkList.h"

int main(int argc, const char * argv[]) {
    StaticLinkList L;
    int i;
    int ret;
    ElemType e;
    
    printf("\n**********01-InitStaticLinkList-TEST-BEGIN************\n");     //  01.函数InitStaticLinkList测试
    {
        printf("\n开始初始化链式结构线性表L\n");
        ret = InitStaticLinkList(L);
        if (ret == OK) {
            printf("\n静态链表L初始化成功\n");
        }else{
            printf("\n静态链表L初始化失败\n");
        }
        
    }
    printf("\n***********01-InitStaticLinkList-TEST-END***********\n\n");

    printf("\n***********02-StaticLinkListInsert-TEST-BEGIN***********\n");     // 02.函数StaticLinkListInsert测试
    {
        e = 77;
        // 在线性表第一个位置插入元素
        i = 1;
        ret = StaticLinkListInsert(L, i, e);
        if (ret == OK) {
            printf("\n静态链表L插入元素%d到位置%d, 成功\n", e, i);
        }else{
            printf("\n静态链表L插入元素%d到位置%d, 失败\n", e, i);
        }
        
    }
    printf("\n***********02-StaticLinkListInsert-TEST-END***********\n\n");

    printf("\n***********03-GetStaticLinkListElem-TEST-BEGIN***********\n");     // 03.函数GetStaticLinkListElem测试
    {
        ret = GetStaticLinkListElem(L, i, &e);
        if (ret == ERROR) {
            printf("\n获取静态链表L第%d个元素,失败\n", i);
        }else {
            printf("\n获取静态链表L第%d个元素成功, 元素为%d\n", i, e);
        }
        
    }
    printf("\n***********03-GetStaticLinkListElem-TEST-END***********\n\n");


    printf("\n***********04-LocateStaticLinkListElem-TEST-BEGIN***********\n");//04.函数LocateStaticLinkListElem测试
    {
        ret = LocateStaticLinkListElem(L, e);
        if (ret == ERROR) {
            printf("\n获取元素%d在静态链表L中的位置, 失败\n", e);
        }else {
            printf("\n获取元素%d在静态链表L中的位置成功, 位置为%d\n", e, ret);
        }
        
    }
    printf("\n***********04-LocateStaticLinkListElem-TEST-END***********\n\n");
    
    printf("\n***********05-StaticLinkListLength-TEST-BEGIN***********\n");     // 05.函数StaticLinkListLength测试
    {
        ret = StaticLinkListLength(L);
        printf("\n静态链表L长度为%d\n", ret);
    }
    printf("\n***********05-StaticLinkListLength-TEST-END***********\n\n");
    
    printf("\n***********06-StaticLinkListDelete-TEST-BEGIN***********\n");     // 06.函数StaticLinkListDelete测试
    {
        ret = StaticLinkListDelete(L, i);
        if (ret == ERROR) {
            printf("\n链式结构线性表删除位置%d元素失败",i);
        }else{
            printf("\n删除线性表L位置%d元素成功, 元素为%d\n", i, e);
        }
    }
    printf("\n***********06-LinkListDelete-TEST-END***********\n\n");

    printf("\n***********07-LinkListEmpty-TEST-BEGIN***********\n");     // 07.函数StaticLinkListEmpty测试
    {
        int empty = StaticLinkListIsEmpty(L);
        if (empty) {
            printf("\n线性表为空\n");
        }else{
                printf("\n线性表不为空");
        }
    }
    printf("\n***********07-LinkListEmpty-TEST-END***********\n\n");
    return 0;
}
