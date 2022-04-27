//
// Created by jiatianlong on 2022/4/26.
// 友元函数
//
#include "iostream"
class Student{
private:
    int age;
    int height;

public:
    int getAge() const {
        return age;
    }

    int getHeight() const;

    friend void upDateHeight(Student* student,int age,int height);
};

void upDateAge(Student* student,int age){
    //这么写是错的，因为age是私有的。无法访问
    //student->age=age;
}

// 友元函数，可以访问Student中的私有对象
// 不需要加类名
void upDateHeight(Student* student,int age,int height){
    student->age = age;
    student->height=height;
}

int Student::getHeight() const {
    return height;
}

int main(){
    Student student;
    upDateHeight(&student,18,180);
    printf("age %d,height %d\n",student.getAge(),student.getHeight());
}