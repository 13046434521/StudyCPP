//
// Created by jiatianlong on 2022/4/28.
// C++ 有多继承
//
#include "iostream"
class Drinks{
public:
    int price;

    Drinks(int price) : price(price) {
        printf("Drink 构造函数\n");
    }
};
class Tea:public Drinks{
public:
    Tea(int price) : Drinks(price) {
        printf("Tea 构造函数\n");
    }

    void drink(){
        printf("Tea 味道很棒\n");
    }

    void sell(){
        printf("Tea 25块钱一杯\n");
    }
};
class Milk:public Drinks{
public:
    Milk(int price) : Drinks(price) {
        printf("Milk 构造函数\n");
    }

    void drink(){
        printf("Milk 味道有点甜\n");
    }

    void sell(){
        printf("Milk 10块钱一盒\n");
    }
};
class Coffe:public Drinks{
public:
    Coffe(int price) : Drinks(price) {
        printf("Coffe 构造函数\n");
    }

    void drink(){
        printf("Coffe 有点苦\n");
    }

    void sell(){
        printf("Coffe 15块钱一杯\n");
    }
};
class TeaCoffeMike:public Tea,public Coffe,public Milk{
public:
    TeaCoffeMike(int price) : Milk(price), Coffe(price), Tea(price) {
        printf("TeaCoffeMike 构造函数\n");
    }

    void sell(){
        printf("TeaCoffeMike 50块钱一杯\n");
    }
};

int main(){
    TeaCoffeMike teaCoffeMike(12);
    // 多个父类中都实现了该方法，所以不能直接调用，出现二义性
    // teaCoffeMike.drink();

    // 方案1： 通过父类:: 告诉编译器调用哪个父类的方法
    teaCoffeMike.Coffe::drink();
    // 方案2：子类重写该方法
    teaCoffeMike.sell();
}