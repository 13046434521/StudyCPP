//
// Created by jiatianlong on 2022/4/24.
// 静态属性方法
// 静态属性，必须先生明，再赋值
// 静态属性赋值时：类型 类::属性  int Person::age = 20;
// 静态方法：类::方法名 Person::staticUpDate();只能调用静态方法
// 静态方法：对象.方法名  person->staticUpDate();
#include "iostream"

using namespace std;
class Person{
public:
    static int age ;

    void update(){
        age +=10;
    }

    static void staticUpDate();
};

void Person::staticUpDate() {
    age+=10;
}
int Person::age = 20;
int main(){
    Person* person = new Person();
    person->age = 30;
    cout<<person->age<<endl;
    person->update();
    cout<<person->age<<endl;
    person->staticUpDate();
    cout<<person->age<<endl;
    Person::staticUpDate();
    cout<<person->age<<endl;
}
