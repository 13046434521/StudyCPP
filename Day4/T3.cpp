//
// Created by jiatianlong on 2022/4/25.
// C++中的this
// this 是指针常量

#include "iostream"
using namespace std;
class Student{
private:
    int age;
    char* name;
    static int height;
public:
    void setAge(int age){
        // this 代表 Student * const 这个类型的指针常量。
        // 所以可以修改里面的值。
        this->age = age;
    }

    void setName(char* name){
        this->name = name;
    }

    static void setHeight(int height){
        Student::height = height;
    }

    char* getName(){
        return this->name;
    }

    int getAge(){
        return this->age;
    }

    ~Student(){
        cout<<"析构函数:"<<this<<endl;
    }
};

int Student::height = 180;

int main(){
    Student student;
    student.setAge(20);
    Student student1;
    student1.setAge(30);
    cout<<"student:"<<&student<<endl;
}
