//
// Created by jiatianlong on 2022/4/24.
//
//

#include "iostream"
#include "string.h"
class Student{
public:
    char * name;
public:
    Student(const Student& student){
//        // ǳ������������ڶ��ϴ������ڴ棬��ָ��ͳһ���ڴ��ַ��������ڴ������ͷţ��ᵼ�±���
        this->name = student.name;
//        // ����� �ڶ��ϴ������ڴ棬����ʱ�������ݿ������´������ڴ��С�
////        this->name = (char *) malloc(1024);
////        strcpy(this->name,student.name);
//
        printf("�������캯��:������ַ:%p,this��ַ:%p\n",&student,this);
        printf("�������캯��:����.name:%p,this.name��ַ:%p\n",student.name,this->name);
    }

    Student(char *name){
//        this->name = name;
        this->name =(char *) malloc(1024);
        strcpy(this->name,name);
        printf("�вι��캯��:%p\n",this);
    }

    ~Student(){
//        free(name);
//        name = nullptr;
        printf("��������:%p\n",this);
    }
};


// ��ִ�п������캯��
Student getStudent1(Student stu){
    stu.name =(char *) "���޼�";
    printf("getStudent��ַ:%p\n",&stu);
    return stu;
}
int main(){
    Student student((char *)"лѷ");
    printf("main:%p\n",&student);

    Student student1 = getStudent1(student) ;

    printf("main:student.name:%p\n",student.name);
    printf("main��student1.name:%p\n",student1.name);
    printf("main:%p\n",&student1);
}
/*
 *�޲ι��캯�� STU1000
 * main STU1000
 * �вι��캯�� STU2000
 * getStudent STU2000
 * �������캯�� STU2000,STU3000
 * �������� STU2000
 * main STU3000
 * �������� STU3000
 * �������� STU1000
 */
