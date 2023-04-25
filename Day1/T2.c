//
// Created by Administrator on 2022/4/20.
//

#include "stdio.h"

// C中的常量：伪常量可以修改
int main() {
    const int name = 1000;
    int *name_p = &name;
    *name_p = 10;
    printf("%d", name);
}