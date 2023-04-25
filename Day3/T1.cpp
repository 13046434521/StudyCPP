//
// Created by jiatianlong on 2022/4/24.
//
//

#include "iostream"
class Student{
private:
    char * name;
    int age;
    int height;
public:
    Student(const Student& student){
        printf("�������캯��:������ַ:%p,this��ַ:%p\n",&student,this);
    }

    Student(char *name, int age=10, int height=180) : name(name), age(age), height(height) {
        printf("�вι��캯��:%p\n",this);
    }
    Student() {
        printf("�޲ι��캯��:��ַ:%p,NAME:%s,AGE:%d,HEIGHT:%d\n",this,name,age,height);
    }
    ~Student(){
        printf("��������:%p\n",this);
    }
};

Student getStudent(char* name){
    Student student(name);

    printf("getStudent��ַ:%p\n",&student);

    return student;
}

int main(){
    Student student;
    printf("main:%p\n",&student);
    Student student1 = getStudent((char *)"���޼�") ;

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
