//
// Created by jiatianlong on 2022/4/21.
//

#include "Student.h"

int Student::getAge() {
    return this->age;
}

char *Student::getName() {
    return this->name;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setName(char *name) {
    this->name = name;
}

Student::Student(char *data, int data2) : name(data), age(data2) {
    printf("Student构造器:%s,%s,%d,%d\n",data,name,data2,age);
}
