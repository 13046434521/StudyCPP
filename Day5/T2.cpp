//
// Created by jiatianlong on 2022/4/27.
// ���������
#include "iostream"
class Student{
public:
    int age;
    int height;

public:
    Student(){};
    Student(int age,int height):age(age),height(height){}

    // ����������
    // д��������Ե���˽������
    // �ó������ã�ֻ�ܶ�����д��
    // ע��C++����Ϊ�˷�ֹ�û��޸ĳ��������б�����ֵ����ֹ���ó������õķ�������Ϊ�������˻��ڷ������޸����Ե�ֵ
    // getAge(){age = age+10}; Ϊ�˷�ֹ�����޸�age��ֵ�����Գ������ý�ֹ���÷�����
    // Student studentSet = student1 + student2 ; this ָ����һ������student��student2���ǵڶ�������
    // ��ôд���Խ�Լ���ܡ�ʡȥһ�ο���������
    Student operator + (const Student& student){
        Student stu;
        stu.age = this->age+student.age;
        stu.height = this->height+student.height;
        printf("%p,%p\n",this,&student);
        return stu;
    }

    void operator ++(){
        this->age+=1;
        this->height+=1;
        printf("ǰ��++��++()\n");
    }
    void operator ++(int){
        this->age+=1;
        this->height+=1;
        printf("����++��++(int)\n");
    }

    friend void operator << (istream &_START,Student student){

    }

};




int main(){
    Student student1(20,180);
    Student student2(29,174);

    // ��д�˲�����������student�������ִ��+����
    Student studentSet = student1 + student2 ;

    Student studentNew = studentSet  + studentSet;
    std::cout<<studentNew.age<<"---"<<studentNew.height<<std::endl;
    studentNew++;
    std::cout<<studentNew.age<<"---"<<studentNew.height<<std::endl;
    ++studentNew;
    std::cout<<studentNew.age<<"---"<<studentNew.height<<std::endl;
}

