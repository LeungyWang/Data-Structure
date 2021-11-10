//
//  main.c
//  01 SequenceList
//
//  Created by leung on 2021/10/17.
//

#include <stdio.h>
#include "SequenceList.h"

int main(int argc, const char * argv[]) {
    SqList L;
    int i;
    int ret;
    ElemType e;
    
    printf("\n**********01-InitList-TEST-BEGIN************\n");     //  01.函数InitList测试
    {
        printf("\n开始初始化线性表L\n");
        ret = InitList(&L);
        if (ret == OK) {
            printf("\n线性表L初始化成功\n");
        }else{
            printf("\n Test Fail!. ");
        }
        
    }
    printf("\n***********01-InitList-TEST-END***********\n\n");
    
    printf("\n***********02-ListEmpty-TEST-BEGIN***********\n");     // 02.函数ListEmpty测试
    {
        int empty = ListEmpty(L);
        if (empty) {
            printf("\n线性表为空\n");
        }else{
                printf("\n线性表不为空");
        }
    }
    printf("\n***********02-ListEmpty-TEST-END***********\n\n");
    
    printf("\n***********03-ListInsert-TEST-BEGIN***********\n");     // 03.函数InsertList测试
    {
        e = 77;
        // 在线性表第一个位置插入元素
        i = 1;
        ret = ListInsert(&L, i, e);
        if (ret == OK) {
            printf("\n线性表L插入元素%d到位置%d, 成功\n", e, i);
        }else{
            printf("\n线性表L插入元素%d到位置%d, 失败\n", e, i);
        }
        
    }
    printf("\n***********03-ListInsert-TEST-END***********\n\n");
    
    printf("\n***********04-GetElem-TEST-BEGIN***********\n");     // 04.函数GetElem测试
    {
        ret = GetElem(L, i, &e);
        if (ret == ERROR) {
            printf("\n获取线性表L第%d个元素,失败\n", i);
        }else {
            printf("\n获取线性表L第%d个元素成功, 元素为%d\n", i, e);
        }
        
    }
    printf("\n***********04-GetElem-TEST-END***********\n\n");
    
    printf("\n***********05-LocateElem-TEST-BEGIN***********\n");     // 05.函数LocateElem测试
    {
        ret = LocateElem(L, e);
        if (ret == ERROR) {
            printf("\n获取元素%d在线性表L中的位置, 失败\n", e);
        }else {
            printf("\n获取元素%d在线性表L中的位置成功, 位置为%d\n", e, ret);
        }
        
    }
    printf("\n***********05-LocateElem-TEST-END***********\n\n");
    
    printf("\n***********06-ListLength-TEST-BEGIN***********\n");     // 06.函数ListLength测试
    {
        ret = ListLength(L);
        printf("\n线性表L长度为%d\n\n", ret);
    }
    printf("\n***********06-ListLength-TEST-END***********\n\n");
    
    printf("\n***********07-ListDelete-TEST-BEGIN***********\n");     // 07.函数ListDelete测试
    {
        ret = ListDelete(&L, i, &e);
        if (ret == ERROR) {
            printf("\n线性表删除位置%d元素失败",i);
        }else{
            printf("\n删除线性表L位置%d元素成功, 元素为%d\n", i, e);
        }
    }
    printf("\n***********07-ListDelete-TEST-END***********\n\n");
    
    
    printf("\n***********08-ClearList-TEST-BEGIN***********\n");     // 08.函数ClearList测试
    {
        ret = ClearList(&L);
        if (ret == OK) {
            printf("\n清空线性表L成功\n");
        }
    }
    printf("\n***********08-ClearList-TEST-END***********\n\n");

    return 0;
    
}
