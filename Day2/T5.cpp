//
// Created by Administrator on 2022/4/23.
// 5. 常量指针：const int * p;
//    指针常量: int * const p;
//    常量指针常量：const int * const p;
//
#include "iostream"
int main(){
    printf("*******************常量指针：***********************\n");
    int num1 = 200;
    int num2 = 100;

    const int* p1 = &num1;
    p1 = &num2;
//    *p1 = 300; 常量指针：不能修改指针指向的地址中的常量值，可以修改指针指向的地址

    printf("\n*******************指针常量：***********************\n");
     int* const p2 = &num1;
//    p2 = &num2; 指针常量:可以修改指针指向的内存地址，不能修改指针指向的内存地址中的常量
    *p2 = 300;
    printf("\n*******************常量指针常量：***********************\n");
    const int*const p3 = &num1;
    // 常量指针常量：指针指向的地址和指针指向的地址中的值都不能改变
//    p3 = &num2;
//    p3 = nullptr;
//    *p3 = 300;
}