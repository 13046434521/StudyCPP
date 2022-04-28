//
// Created by jiatianlong on 2022/4/28.
// C++  多继承二义性
// 虚基类 virtual
//
#include "iostream"

class Drinks {
public:
    int price;

    Drinks(int price) : price(price) {
        printf("Drink 构造函数\n");
    }

    void drink() {
        printf("Drink 喝饮料\n");
    }

    void sell() {
        printf("Drink 的价格\n");
    }
};

class Tea : virtual public Drinks {
public:
    Tea(int price) : Drinks(price) {
        printf("Tea 构造函数\n");
    }


};

class Milk : virtual public Drinks {
public:
    Milk(int price) : Drinks(price) {
        printf("Milk 构造函数\n");
    }

    void drink() {
        printf("Milk 喝牛奶\n");
    }
};

class Coffe : virtual public Drinks {
public:
    Coffe(int price) : Drinks(price) {
        printf("Coffe 构造函数\n");
    }

    void drink() {
        printf("Coffe 喝咖啡\n");
    }
};

class TeaCoffeMike : public Tea, public Coffe, public Milk {
public:
    TeaCoffeMike(int price) : Drinks(price), Milk(price), Coffe(price), Tea(price) {
        printf("TeaCoffeMike 构造函数\n");
    }

};

int main() {
    TeaCoffeMike teaCoffeMike(12);
    // 由于多个父类继承祖父类时 被virtual修饰。
    // 所以只要父类中没有重写祖父类的方法。调用时都是使用祖父类的方法
    // 一旦有一个父类重写了，就会默认调用父类重写的方法
    // 如果多个父类重写了该方法，即便被virtual修饰，扔会出现二义性
    // teaCoffeMike.drink();
    // 方案1： 通过父类:: 告诉编译器调用哪个父类的方法
    teaCoffeMike.Tea::drink();
    // 方案2：子类重写该方法
    teaCoffeMike.sell();
}