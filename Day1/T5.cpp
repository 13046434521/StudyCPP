//
// Created by Administrator on 2022/4/21.
// ��������
//

#include "iostream"
#include "string.h"
typedef struct Student{
    char* name ;
    int age;
} Xiexun;

// ISO C++11 does not allow conversion from string literal to 'char *'
// char * ����ǿת�� char * ���Ҳ���delete
void change(Student& student){
    student.name =(char *) "���޼�";// ���� delete(student.name);
    student.age = 29;
}

//�������ã��޷��޸�
// student������ݲ��ܸģ�student����Ҳ���ܸ�ֵΪ���Student
//void changeConst(const Student& student){
//    student.name = "������";// ����д��
//    student.age = 27;// ����д��
//}
int main(){
    Xiexun xiexun ={(char *)"лѷ",58};
    change(xiexun);
    printf("����:%s,����:%d\n",xiexun.name,xiexun.age);
//    changeConst(xiexun);
//    printf("����:%s,����:%d\n",xiexun.name,xiexun.age);

    return 0;
}