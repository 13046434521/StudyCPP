//
// Created by Administrator on 2022/4/23.
// 4.拷贝构造函数
//  对象=对象 执行拷贝构造函数
//  指针=指针 不执行拷贝构造函数

#include "iostream"

class Student {
public:
    Student() {}

    Student(Student &student) {
        printf("拷贝构造函数:%p\n", &student);
        this->name = student.name;
        this->height = student.age;
        this->age = student.height;
    }

    Student(char *name, int age, int height) : name(name), age(age), height(height) {
        printf("构造函数\n");
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

// 拷贝构造函数
int main() {

    printf("*******************堆中创建对象:指针指向内存地址***********************\n");
    printf("*******************堆中创建对象:不执行拷贝构造函数***********************\n");
    // 两个指针指向同一块内存，所以不执行拷贝构造函数
    Student *stu = new Student((char *) "张无忌", 29, 180);
    Student *stu1 = stu;// stu1和stu指向同一块内存，
//    stu = nullptr;
    printf("student:%p\n", stu);
    printf("student:%p\n", stu1);

    printf("name:%s,age:%d,height:%d\n", stu1->getName(), stu1->getAge(), stu1->getHeight());

    printf("\n*******************栈中创建对象:正常拷贝构造函数***********************\n");
    // 会执行自定义拷贝构造函数
    Student student((char *) "谢逊", 60, 190);
    Student student1 = student;
    printf("student:%p\n", &student);
    printf("name:%s,age:%d,height:%d\n", student1.getName(), student1.getAge(), student1.getHeight());


    printf("\n*******************栈中创建对象:默认拷贝构造函数***********************\n");
    // 会执行默认拷贝构造函数
    Student student2;
    student2 = student;

    printf("student:%p\n", &student);
    printf("name:%s,age:%d,height:%d\n", student2.getName(), student2.getAge(), student2.getHeight());
}