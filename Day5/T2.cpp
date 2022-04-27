//
// Created by jiatianlong on 2022/4/27.
// 运算符重载
#include "iostream"
class Student{
public:
    int age;
    int height;

public:
    Student(){};
    Student(int age,int height):age(age),height(height){}

    // 操作符重载
    // 写在类里可以调用私有属性
    // 用常量引用，只能读不能写，
    // 注意C++这里为了防止用户修改常量引用中变量的值，禁止调用常量引用的方法。因为可能有人会在方法中修改属性的值
    // getAge(){age = age+10}; 为了防止这样修改age的值，所以常量引用禁止调用方法。
    // Student studentSet = student1 + student2 ; this 指代第一个对象：student，student2：是第二个对象
    // 这么写可以节约性能。省去一次拷贝函数。
    Student operator + (const Student& student){
        Student stu;
        stu.age = this->age+student.age;
        stu.height = this->height+student.height;
        printf("%p,%p\n",this,&student);
        return stu;
    }

    void operator ++(){
        this->age+=1;
        this->height+=1;
        printf("前置++：++()\n");
    }
    void operator ++(int){
        this->age+=1;
        this->height+=1;
        printf("后置++：++(int)\n");
    }

    friend void operator << (istream &_START,Student student){

    }

};




int main(){
    Student student1(20,180);
    Student student2(29,174);

    // 重写了操作符，所以student对象可以执行+操作
    Student studentSet = student1 + student2 ;

    Student studentNew = studentSet  + studentSet;
    std::cout<<studentNew.age<<"---"<<studentNew.height<<std::endl;
    studentNew++;
    std::cout<<studentNew.age<<"---"<<studentNew.height<<std::endl;
    ++studentNew;
    std::cout<<studentNew.age<<"---"<<studentNew.height<<std::endl;
}

