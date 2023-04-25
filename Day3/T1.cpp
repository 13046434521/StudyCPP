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
        printf("拷贝构造函数:参数地址:%p,this地址:%p\n",&student,this);
    }

    Student(char *name, int age=10, int height=180) : name(name), age(age), height(height) {
        printf("有参构造函数:%p\n",this);
    }
    Student() {
        printf("无参构造函数:地址:%p,NAME:%s,AGE:%d,HEIGHT:%d\n",this,name,age,height);
    }
    ~Student(){
        printf("析构函数:%p\n",this);
    }
};

Student getStudent(char* name){
    Student student(name);

    printf("getStudent地址:%p\n",&student);

    return student;
}

int main(){
    Student student;
    printf("main:%p\n",&student);
    Student student1 = getStudent((char *)"张无忌") ;

    printf("main:%p\n",&student1);
}
/*
 *无参构造函数 STU1000
 * main STU1000
 * 有参构造函数 STU2000
 * getStudent STU2000
 * 拷贝构造函数 STU2000,STU3000
 * 析构函数 STU2000
 * main STU3000
 * 析构函数 STU3000
 * 析构函数 STU1000
 */
