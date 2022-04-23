//
// Created by jiatianlong on 2022/4/21.
//
#include "iostream"

using namespace std;

class Student {
public:
    Student(char *data1, int data2);

private:
    char *name;
    int age;
public:
    char *getName();

    int getAge();

    void setName(char *name);

    void setAge(int age);
};

