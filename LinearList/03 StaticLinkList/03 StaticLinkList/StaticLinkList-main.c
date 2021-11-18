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
    
    printf("\n**********01-InitStaticLinkList-TEST-BEGIN************\n");     //  01.函数InitLinkList测试
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

    
    return 0;
}
