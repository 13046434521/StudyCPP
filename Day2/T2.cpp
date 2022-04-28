//
// Created by jiatianlong on 2022/4/22.
//构造函数
#include "iostream"
class Student{
public:
    // :height(height) 等价于 this->height=height;
    // 初始化列表
    Student(char *name,int age,int height):height(age),age(height),name(name){
//        this->age = age;
//        this->height = height;
//        this->name = name;
        printf("三个参数:name:%s,age:%d,height:%d\n",name,age,height);

        // 动态开辟内存,为了演示析构函数
        this->test = (char *)malloc(1024);
    }

    Student(char *name, int age) {
        printf("空参构造函数\n");
    }

    // 默认调用:Student(char*name,int age,int height),再调用本身
    Student(char* name): Student(name,28,190){
        printf("一个参构造函数\n");
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

    // 栈中开辟的对象，出栈时自动调用析构函数
    // 堆中开辟的对象，delete(对象)时调用析构函数. free(对象)不会调用析构函数
    ~Student(){
        printf("析构函数?\n");
        // 释放动态开辟的内存
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
    Student stu ((char *)"张无忌");
    Student *student = new Student((char *)"谢逊",60,180);
    printf("name:%s,age:%d,height:%d\n",student->getName(),student->getAge(),student->getHeight());
    delete(student);
    student =NULL;
}