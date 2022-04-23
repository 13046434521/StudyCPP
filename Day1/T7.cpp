//
// Created by jiatianlong on 2022/4/21.
// C++ 允许重载，C++允许给参数赋默认值
// C++ 函数，不能既有重载，又有赋默认参数的形式
// 编译器不知道是找重载方法，还是有默认值得方法，从而出现二义性
//

#include "iostream"

using namespace std;

void add(int num1){

}

void add(int num1,int num2){

}

void add(int num1 =100,int num2=200,int num3=300){

}

int main(){
    int num1 = 1;
    int num2 = 2;

    // 这里由于有两个参数的重载方法,也有有三个默认值的重载方法
    // 编译器，不知道是找两个参数的重载方法，还是有三个默认值的重载方法：前两个参数传值，第三个为默认值的方法
    // 二义性
    add(num1,num2);
}
