//
//  StaticLinkList.c
//  03 StaticLinkList
//
//  Created by leung on 2021/11/10.
//

#include "StaticLinkList.h"

/*************************************************
Function:  InitStaticLinkList
Description:  初始化静态链表
Input:
    (StaticLinkList)    *L
Return: (int)   函数执行状态码,
          1为成功, 0为失败
*************************************************/
Status InitStaticLinkList(StaticLinkList space)
{
    int i;
    for (i=0; i<MAXSIZE-1; i++) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE-1].cur = 0;   /*目前静态链表为空, 最后一个元素的cur为0*/
}
