//
// Created by jiatianlong on 2022/4/24.
// 1. 可变参数
//
#include "stdarg.h"//支持可变参数头文件
#include "iostream"
void getData(int count ,...){
    va_list  vaList;
    // 将vaList指向可变参数头地址
    va_start(vaList,count);

    for (int i = 0; i < count; ++i) {
        // va_arg :取出当前指针指向的可变参数
        // 第一个参数：可变参数列表
        // 第二个参数：类型
        printf("%d\n", va_arg(vaList,int));
    }

    //vaList置空
    va_end(vaList);
}


int main(){
    getData(10,8,9,"1","2",3.0f);
}
