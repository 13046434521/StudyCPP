//
// Created by jiatianlong on 2022/4/21.
//

#include "Student.h"
int main(){
    printf("------------栈空间------------\n");
    Student student ={(char *)"张无忌",29};
    student.setName((char *)"谢逊");
    student.setAge(50);

    printf("name:%s,age:%d\n",student.getName(),student.getAge());
    printf("------------堆空间------------\n");
    Student* student1 = new Student((char *)"灭绝师太",60);
    student1->setAge(27);
    student1->setName((char *)"周芷若");
    printf("name:%s,age:%d\n",student1->getName(),student1->getAge());

    delete(student1);
    student1= NULL;
}
