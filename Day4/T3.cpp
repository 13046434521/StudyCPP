//
// Created by jiatianlong on 2022/4/25.
// C++�е�this
// this ��ָ�볣��

#include "iostream"
using namespace std;
class Student{
private:
    int age;
    char* name;
    static int height;
public:
    void setAge(int age){
        // this ���� Student * const ������͵�ָ�볣����
        // ���Կ����޸������ֵ��
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
        cout<<"��������:"<<this<<endl;
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
