//
// Created by jiatianlong on 2022/4/27.
// 友元类
// 类A中定义类B为友元类
// 可以在类B中调用，类A的私有属性

#include "iostream"

using namespace std;
class Student{
private:
    int age;
    int klass;
    friend class Grade;
public:
    void setAge(int age){
        this->age = age;
    }

    int getAge(){
        return this->age;
    }
    void setKlass(int klass){
        this->klass = klass;
    }

    int getKlass(){
        return this->klass;
    }
};

class Grade {
private:

public:
    void setKLass(Student &st, int klass) {
        st.klass = klass;
    };
};

int main(){
    Student student ;
    student.setAge(10);
    Grade grade;
    grade.setKLass(student,20);

    cout<<student.getAge()<<endl;
}