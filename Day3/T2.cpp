//
// Created by jiatianlong on 2022/4/24.
//
//

#include "iostream"
#include "string.h"
class Student{
public:
    char * name;
public:
    Student(const Student& student){
//        // 浅拷贝：如果是在堆上创建的内存，会指向统一块内存地址，如果该内存连续释放，会导致崩溃
        this->name = student.name;
//        // 深拷贝： 在堆上创建的内存，拷贝时，将数据拷贝到新创建的内存中。
////        this->name = (char *) malloc(1024);
////        strcpy(this->name,student.name);
//
        printf("拷贝构造函数:参数地址:%p,this地址:%p\n",&student,this);
        printf("拷贝构造函数:参数.name:%p,this.name地址:%p\n",student.name,this->name);
    }

    Student(char *name){
//        this->name = name;
        this->name =(char *) malloc(1024);
        strcpy(this->name,name);
        printf("有参构造函数:%p\n",this);
    }

    ~Student(){
//        free(name);
//        name = nullptr;
        printf("析构函数:%p\n",this);
    }
};


// 会执行拷贝构造函数
Student getStudent1(Student stu){
    stu.name =(char *) "张无忌";
    printf("getStudent地址:%p\n",&stu);
    return stu;
}
int main(){
    Student student((char *)"谢逊");
    printf("main:%p\n",&student);

    Student student1 = getStudent1(student) ;

    printf("main:student.name:%p\n",student.name);
    printf("main：student1.name:%p\n",student1.name);
    printf("main:%p\n",&student1);
}
/*
 *无参构造函数 STU1000
 * main STU1000
 * 有参构造函数 STU2000
 * getStudent STU2000
 * 拷贝构造函数 STU2000,STU3000
 * 析构函数 STU2000
 * main STU3000
 * 析构函数 STU3000
 * 析构函数 STU1000
 */
