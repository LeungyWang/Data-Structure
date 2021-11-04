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
            printf("\n Test Fail!. ");
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

    printf("\n***********04-LocateLinkListElem-TEST-BEGIN***********\n");     // 05.函数LocateElem测试
    {
        ret = LocateLinkListElem(L, e);
        if (ret == ERROR) {
            printf("\n获取元素%d在链式结构线性表L中的位置, 失败\n", e);
        }else {
            printf("\n获取元素%d在链式结构线性表L中的位置成功, 位置为%d\n", e, ret);
        }
        
    }
    printf("\n***********04-LocateLinkListElem-TEST-END***********\n\n");

    
}
