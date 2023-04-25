//
// Created by jiatianlong on 2022/4/27.
//
// 类的方法实现：需要加  类名::
// 普通方法: 返回值 类名::
// 静态方法: 和普通方法一样，不需要加static
// 友元函数: 不需要加 类名::

#include "Pig.h"

Pig::Pig() {
    cout << "构造函数:地址："<<this<<  endl;
}

Pig::Pig(char *name) {
    this->name = name;
    cout << "构造函数:一个参数:地址："<<this<< " name:" << name << endl;
}

Pig::Pig(char *name, int age) : name(name), age(age) {
    cout << "构造函数:两个参数:地址："<<this<< " name:" << name << " age:" << age << endl;
}

Pig::Pig(const Pig &pig) {
    cout << "拷贝构造函数:传入参数pig地址：" << &pig << " 新对象this地址:" << this << endl;
}

void Pig::showPigInfo() const {
    cout << "普通函数:showPigInfo:this地址：" << this <<" name:"<<name<<" age:"<<age<< endl;
}

void Pig::setName(char *name) {
    this->name = name;
    cout << "普通函数:setName:this地址：" << this << endl;
}

void Pig::setAge(int age) {
    this->age =age;
    cout << "普通函数:setAge:this地址：" << this << endl;
}

void Pig::setPig(Pig &pig) {
    //this = pig; 错误写法，this是个指针常量
    this->name = pig.name;
    this->age = pig.age;

    cout << "普通函数:setPig:pig地址:" << &pig << " this地址：" << this << endl;
}

int Pig::getAge() {
    cout<<"普通函数：getAge:this地址："<<this<< " age:"<<age<<endl;
    return this->age;
}

char *Pig::getName() {
    cout<<"普通函数：getName:this地址："<<this<< " name:"<<name<<endl;
    return this->name;
}

void Pig::Update(Pig *pig) {
    cout << "静态函数:无法调用this：传入对象地址：" << pig << endl;
}

int Pig::height = 180;

void friendPig(Pig pig, char *name, int age) {
    pig.name = name;
    pig.age = age;
    cout << "友元函数:可以调用类的私有属性：传入对象地址：" << &pig <<" name："<<pig.name<<" age："<<pig.age<< endl;
}


Pig::~Pig() {
    cout << "析构函数:对象地址：" << this << endl;
}


