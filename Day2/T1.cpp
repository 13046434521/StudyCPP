//
// Created by jiatianlong on 2022/4/21.
//
#include "stdio.h"
// 自定义namespace：命名空间
namespace jtl{
    int age;
    char* name;

    void show(char*name,int age){
        printf("name:%s,age:%d\n",name,age);
    }
}
using namespace jtl;
int main(){
    jtl::show((char *)"贾天龙",29);

    return 0;
}
