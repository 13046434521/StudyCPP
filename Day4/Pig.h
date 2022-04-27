//
// Created by jiatianlong on 2022/4/27.
//
#ifndef PIG_H
#define PIG_H

#include "iostream"
using namespace std;


class Pig {
private:
    char * name;
    int age;
public:
    static int height;
    // 构造函数
    Pig();
    Pig(char *name);
    Pig(char *name,int age);

    // 拷贝构造函数
    Pig(const Pig& pig);

    // 析构函数
    ~Pig();

    // 正常函数声明
    void setName(char *name);
    void setAge(int age);
    void setPig(Pig &pig);

    //常量函数
    void showPigInfo() const;//

    char *getName();
    int getAge();

    // 静态方法
    static void Update(Pig* pig);
    // 友元函数
    friend void friendPig(Pig pig,char*name,int age);
};


#endif //STUDYCPP_PIG_H
