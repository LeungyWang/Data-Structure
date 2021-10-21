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
    ElemType e;
    
    printf("\n***01-InitList-TEST***\n");
    {
        printf("\n开始初始化线性表L\n");
        InitList(&L);
        printf("\n线性表L初始化成功\n");
    }
    printf("\n***01-InitList-TEST***\n");
    
    printf("\n***2-ListEmpty-TEST***\n");
    return 0;
    
}
