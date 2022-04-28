//
// Created by jiatianlong on 2022/4/22.
//���캯��
#include "iostream"
class Student{
public:
    // :height(height) �ȼ��� this->height=height;
    // ��ʼ���б�
    Student(char *name,int age,int height):height(age),age(height),name(name){
//        this->age = age;
//        this->height = height;
//        this->name = name;
        printf("��������:name:%s,age:%d,height:%d\n",name,age,height);

        // ��̬�����ڴ�,Ϊ����ʾ��������
        this->test = (char *)malloc(1024);
    }

    Student(char *name, int age) {
        printf("�ղι��캯��\n");
    }

    // Ĭ�ϵ���:Student(char*name,int age,int height),�ٵ��ñ���
    Student(char* name): Student(name,28,190){
        printf("һ���ι��캯��\n");
    }

    char *getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    int getHeight() const {
        return height;
    }

    // ջ�п��ٵĶ��󣬳�ջʱ�Զ�������������
    // ���п��ٵĶ���delete(����)ʱ������������. free(����)���������������
    ~Student(){
        printf("��������?\n");
        // �ͷŶ�̬���ٵ��ڴ�
        if (test){
            free(test);
            test =NULL;
        }
    }

private:
    char *name;
    int age;
    int height;
    char*test;
};

int main(){
    Student stu ((char *)"���޼�");
    Student *student = new Student((char *)"лѷ",60,180);
    printf("name:%s,age:%d,height:%d\n",student->getName(),student->getAge(),student->getHeight());
    delete(student);
    student =NULL;
}