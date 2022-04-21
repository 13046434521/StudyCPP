# StudyCPP

#### 初识C++

##### C和C++的常量区别

    1. C中的常量是伪常量。可以通过指针修改。而C++中的不允许

```c
    #include "stdio.h"
    // C中的常量：伪常量可以修改
    int main(){
        const int  name = 1000;
        int * name_p = &name;
        *name_p = 10;
        printf("%d",name);
    }
```

```c++
    #include "iostream"
    
    // C++ 中，不许对常量进去取值再赋值 的操作。
    // 该写法报错
    int main(){
        const int data = 10;
        int * data_p = &data;// 此处报错
        *data_p = 1000;
        printf("%d",data);
    }
```

##### 引用

    1. 传引用类似于Java中的传对象或者C/C++中的传地址。修改的是同一块内存中的值

```c++
    #include "iostream"
    using namespace std;
    
    // 直接在内存地址上操作
    void changeData(int * num1,int *num2){
        int temp = *num1;
        *num1 = *num2;
        *num2 = temp;
        printf("%p,%p\n",num1,num2);
    }
    
    // 传引用：类似于Java传的是同一个对象，在方法中修改对象，就会
    void changeData(int &num1,int &num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
        printf("%p,%p\n",&num1,&num2);
    }
    
    int main(){
        int num1 = 100;
        int num2 = 200;
        changeData(&num1,&num2);
        printf("----------传地址----------\n");
        printf("%d,%d,%p,%p\n",num1,num2,&num1,&num2);
    
        printf("----------传引用----------\n");
        changeData(num1,num2);
        printf("%d,%d,%p,%p\n",num1,num2,&num1,&num2);
    
    
        // data 和 data2 都指向同一片内存。
        int data = 999;
        int &data2 = data;
        data2 = 200;
    
        printf("%d,%p,%p",data,&data,&data2);
    }
```

    2. 结构体引用中的参数，char*类型的赋值，必须强转成char*,否则报:ISO C++11 does not allow conversion from string literal to 'char *',且不能delete
    3. 常量引用，不能修改值。否则报错

```c++
    #include "iostream"
    #include "string.h"
    typedef struct Student{
        char* name ;
        int age;
    } Xiexun;
    
    // ISO C++11 does not allow conversion from string literal to 'char *'
    // char * 必须强转成 char * 并且不能delete
    void change(Student& student){
        student.name =(char *) "张无忌";// 不能 delete(student.name);
        student.age = 29;
    }
    
    //常量引用，无法修改
    // student里的内容不能改，student本身也不能赋值为别的Student
    //void changeConst(const Student& student){
    //    student.name = "周芷若";// 错误写法
    //    student.age = 27;// 错误写法
    //}
    int main(){
        Xiexun xiexun ={(char *)"谢逊",58};
        change(xiexun);
        printf("名字:%s,年龄:%d\n",xiexun.name,xiexun.age);
    //    changeConst(xiexun);
    //    printf("名字:%s,年龄:%d\n",xiexun.name,xiexun.age);
    
        return 0;
    }
```

    4. C语言没有函数重载，C++有函数重载
    5. C++函数可以赋默认值，但是重载的函数和赋默认值的函数容易出现二义性

```c++
    void add(int num1, int num2){
    
    }
    
    void add(int num1 =100, int num2=200, int num3=300){
    
    }
    
    int main(){
    int num1 = 1;
    int num2 = 2;
    
    // 这里由于有两个参数的重载方法,也有有三个默认值的重载方法
    // 编译器，不知道是找两个参数的重载方法，还是有三个默认值的重载方法：前两个参数传值，第三个为默认值的方法
    // 二义性
    add(num1, num2);
    }
```
    6. C++中可以留有占位符参数，没有意义，存粹为了未来开发方便
```c++
    // 前期开发中只用到了num1，后面3个参数，用来占位
    // 所有调用方法4个参数都必须传
    // 后期如果需要新增功能，用到后三个参数方便修改
    void add(int num1,int ,int ,long){
    
    }
    
    int main(){
    int num1 =10;
    add(10,20,30,40);
    }
```
    7. 正常开发，必须是.h头文件配合.cpp可执行文件
    8. .h头文件：用来声明，.cpp文件用来写实现
    9. new 在堆中开辟空间，delete 用来释放堆中开辟的对象
    10. class中的public用来代表公共的，private是私有的
    11. cpp中实现类中方法的时候需要::  例子:Student::getAge();
    12. 实现的时候，通过this->来调用自己类中的属性和方法
    13. exe文件生成的时候，需要#set(CMAKE_EXE_LINKER_FLAGS "-static")或者target_link_libraries (StudyCPP -static) 编译时添加静态库
```c++
    class Student {
    public:
        Student(char *data1, int data2);

    private:
        char *name;
        int age;
    public:
        char *getName();

        int getAge();

        void setName(char *name);

        void setAge(int age);
    };
    #include "Student.h"

    int Student::getAge() {
        return this->age;
    }

    char *Student::getName() {
        return this->name;
    }

    void Student::setAge(int age) {
        this->age = age;
    }

    void Student::setName(char *name) {
        this->name = name;
    }

    Student::Student(char *data, int data2) : name(data), age(data2) {
        printf("Student构造器:%s,%s,%d,%d\n",data,name,data2,age);

    }
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

```