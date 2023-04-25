//
// Created by jiatianlong on 2022/4/27.
//
// ��ķ���ʵ�֣���Ҫ��  ����::
// ��ͨ����: ����ֵ ����::
// ��̬����: ����ͨ����һ��������Ҫ��static
// ��Ԫ����: ����Ҫ�� ����::

#include "Pig.h"

Pig::Pig() {
    cout << "���캯��:��ַ��"<<this<<  endl;
}

Pig::Pig(char *name) {
    this->name = name;
    cout << "���캯��:һ������:��ַ��"<<this<< " name:" << name << endl;
}

Pig::Pig(char *name, int age) : name(name), age(age) {
    cout << "���캯��:��������:��ַ��"<<this<< " name:" << name << " age:" << age << endl;
}

Pig::Pig(const Pig &pig) {
    cout << "�������캯��:�������pig��ַ��" << &pig << " �¶���this��ַ:" << this << endl;
}

void Pig::showPigInfo() const {
    cout << "��ͨ����:showPigInfo:this��ַ��" << this <<" name:"<<name<<" age:"<<age<< endl;
}

void Pig::setName(char *name) {
    this->name = name;
    cout << "��ͨ����:setName:this��ַ��" << this << endl;
}

void Pig::setAge(int age) {
    this->age =age;
    cout << "��ͨ����:setAge:this��ַ��" << this << endl;
}

void Pig::setPig(Pig &pig) {
    //this = pig; ����д����this�Ǹ�ָ�볣��
    this->name = pig.name;
    this->age = pig.age;

    cout << "��ͨ����:setPig:pig��ַ:" << &pig << " this��ַ��" << this << endl;
}

int Pig::getAge() {
    cout<<"��ͨ������getAge:this��ַ��"<<this<< " age:"<<age<<endl;
    return this->age;
}

char *Pig::getName() {
    cout<<"��ͨ������getName:this��ַ��"<<this<< " name:"<<name<<endl;
    return this->name;
}

void Pig::Update(Pig *pig) {
    cout << "��̬����:�޷�����this����������ַ��" << pig << endl;
}

int Pig::height = 180;

void friendPig(Pig pig, char *name, int age) {
    pig.name = name;
    pig.age = age;
    cout << "��Ԫ����:���Ե������˽�����ԣ���������ַ��" << &pig <<" name��"<<pig.name<<" age��"<<pig.age<< endl;
}


Pig::~Pig() {
    cout << "��������:�����ַ��" << this << endl;
}


