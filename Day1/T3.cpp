//
// Created by Administrator on 2022/4/20.
//

#include "iostream"

// C++ 中，不许对常量进去取值再赋值 的操作
// 该写法报错
int main(){
    const int data = 10;
    int * data_p = &data;// 此处报错
    *data_p = 1000;
    printf("%d",data);
}