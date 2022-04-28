//
// Created by jiatianlong on 2022/4/28.
// ��ļ̳�
// 1. class �̳и��࣬��Ϊprivate��public�̳С���private��public�ؼ���������
// 2. Ĭ������private�̳�
// 3. �������ּ̳У����඼�޷����ʸ����˽�����ԡ�
// 4. private��public�̳С������������õ������public����
// 5. private�̳����������棬�޷����ʸ����public����
// 6. public�̳����������棬���Է��ʸ����public����
#include "iostream"

class Person {
public:
    char *name;
    int age;

public:
    Person(char *name, int age) : name(name), age(age) {
        printf("Person ������\n");
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
        printf("Man ������\n");
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
    China chinese((char *) "���޼�", 12, Man);
    chinese.name = (char *) "������";
    chinese.setSex(WoMan);

    printf("name is %s,\nsex is %d\n", chinese.name, chinese.getSex());
}

