//
// Created by jiatianlong on 2022/4/27.
// 运算符重载
#include "iostream"
class Student{
public:
    int age;
    int height;

public:
    Student() {};
    Student(char *name, int age) {};
    Student(int age,int height):age(age),height(height){}
};

// 操作符重载
Student operator + (Student student1,Student student2){
    Student stu;
    stu.age = student1.age+student2.age;
    stu.height = student1.height+student2.height;
    return stu;
}


int main(){
    Student student1(20,180);
    Student student2(29,174);

    // 重写了操作符，所以student对象可以执行+操作
    Student studentSet = student1+student2 ;
    std::cout<<studentSet.age<<"---"<<studentSet.height<<std::endl;
}

