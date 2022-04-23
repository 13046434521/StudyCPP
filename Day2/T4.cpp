//
// Created by Administrator on 2022/4/23.
// 4.�������캯��
//  ����=���� ִ�п������캯��
//  ָ��=ָ�� ��ִ�п������캯��

#include "iostream"

class Student {
public:
    Student() {}

    Student(Student &student) {
        printf("�������캯��:%p\n", &student);
        this->name = student.name;
        this->height = student.age;
        this->age = student.height;
    }

    Student(char *name, int age, int height) : name(name), age(age), height(height) {
        printf("���캯��\n");
    }

    char *getName() const {
        return name;
    }

    int getHeight() const {
        return height;
    }

    int getAge() const {
        return age;
    }

private:
    char *name;
    int age;
    int height;
};

// �������캯��
int main() {

    printf("*******************���д�������:ָ��ָ���ڴ��ַ***********************\n");
    printf("*******************���д�������:��ִ�п������캯��***********************\n");
    // ����ָ��ָ��ͬһ���ڴ棬���Բ�ִ�п������캯��
    Student *stu = new Student((char *) "���޼�", 29, 180);
    Student *stu1 = stu;// stu1��stuָ��ͬһ���ڴ棬
//    stu = nullptr;
    printf("student:%p\n", stu);
    printf("student:%p\n", stu1);

    printf("name:%s,age:%d,height:%d\n", stu1->getName(), stu1->getAge(), stu1->getHeight());

    printf("\n*******************ջ�д�������:�����������캯��***********************\n");
    // ��ִ���Զ��忽�����캯��
    Student student((char *) "лѷ", 60, 190);
    Student student1 = student;
    printf("student:%p\n", &student);
    printf("name:%s,age:%d,height:%d\n", student1.getName(), student1.getAge(), student1.getHeight());


    printf("\n*******************ջ�д�������:Ĭ�Ͽ������캯��***********************\n");
    // ��ִ��Ĭ�Ͽ������캯��
    Student student2;
    student2 = student;

    printf("student:%p\n", &student);
    printf("name:%s,age:%d,height:%d\n", student2.getName(), student2.getAge(), student2.getHeight());
}