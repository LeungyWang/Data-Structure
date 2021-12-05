//
//  main.c
//  04 CircleList
//
//  Created by leung on 2021/11/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a = 10;
    // b是指针变量 b变量的存储单元存储的是另一个变量的地址
    // *b表示另一个变量的值
    int *b = &a;

    printf("%d\n", a);
    printf("%d\n", &a);
    printf("%d\n", b);
    printf("%d\n", *b);
    return 0;
}
