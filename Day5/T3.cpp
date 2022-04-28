//
// Created by jiatianlong on 2022/4/28.
// 类的继承
// 1. class 继承父类，分为private和public继承。用private和public关键字来区分
// 2. 默认属于private继承
// 3. 无论哪种继承，子类都无法访问父类的私有属性、
// 4. private和public继承。在子类中能拿到父类的public属性
// 5. private继承在子类外面，无法访问父类的public属性
// 6. public继承在子类外面，可以访问父类的public属性
#include "iostream"

class Person {
public:
    char *name;
    int age;

public:
    Person(char *name, int age) : name(name), age(age) {
        printf("Person 构造器\n");
    }

    void setName(char *name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

};

enum Sex {
    Man = 1,
    WoMan
};

class China : public Person {
private:
    Sex sex;
public:
    China(char *name, int age, Sex sex) : Person(name, age), sex(sex) {
        printf("Man 构造器\n");
    }

    void setName(char *name) {
        this->name = name;
    }

    void setSex(Sex sex) {
        this->sex = sex;
    }

    Sex getSex() {
        return this->sex;
    }
};

int main() {
    China chinese((char *) "张无忌", 12, Man);
    chinese.name = (char *) "周芷若";
    chinese.setSex(WoMan);

    printf("name is %s,\nsex is %d\n", chinese.name, chinese.getSex());
}

