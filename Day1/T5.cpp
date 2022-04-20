//
// Created by Administrator on 2022/4/21.
// 常量引用
//

#include "iostream"
#include "string.h"
typedef struct Student{
    char name[20] ;
    int age;
} Xiexun;

void change(Student student){
//    strcpy(student.name,"张无忌");
    student.age = 29;
}

//常量引用，无法修改
//void changeConst(const Student& student){
//    student.name = "周芷若";// 错误写法
//    student.age = 27;// 错误写法
//}
int main(){
//    Xiexun xiexun ={"谢逊",58};
//    change(xiexun);
//    printf("名字:%s,年龄:%d\n",xiexun.name,xiexun.age);
//    changeConst(xiexun);
//    printf("名字:%s,年龄:%d\n",xiexun.name,xiexun.age);

    return 0;
}