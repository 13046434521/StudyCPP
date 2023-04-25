//
// Created by Administrator on 2022/4/21.
// 常量引用
//

#include "iostream"
#include "string.h"
typedef struct Student{
    char* name ;
    int age;
} Xiexun;

// ISO C++11 does not allow conversion from string literal to 'char *'
// char * 必须强转成 char * 并且不能delete
void change(Student& student){
    student.name =(char *) "张无忌";// 不能 delete(student.name);
    student.age = 29;
}

//常量引用，无法修改
// student里的内容不能改，student本身也不能赋值为别的Student
//void changeConst(const Student& student){
//    student.name = "周芷若";// 错误写法
//    student.age = 27;// 错误写法
//}
int main(){
    Xiexun xiexun ={(char *)"谢逊",58};
    change(xiexun);
    printf("名字:%s,年龄:%d\n",xiexun.name,xiexun.age);
//    changeConst(xiexun);
//    printf("名字:%s,年龄:%d\n",xiexun.name,xiexun.age);

    return 0;
}