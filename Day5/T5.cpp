//
// Created by jiatianlong on 2022/4/28.
// C++  ��̳ж�����
// ����� virtual
//
#include "iostream"

class Drinks {
public:
    int price;

    Drinks(int price) : price(price) {
        printf("Drink ���캯��\n");
    }

    void drink() {
        printf("Drink ������\n");
    }

    void sell() {
        printf("Drink �ļ۸�\n");
    }
};

class Tea : virtual public Drinks {
public:
    Tea(int price) : Drinks(price) {
        printf("Tea ���캯��\n");
    }


};

class Milk : virtual public Drinks {
public:
    Milk(int price) : Drinks(price) {
        printf("Milk ���캯��\n");
    }

    void drink() {
        printf("Milk ��ţ��\n");
    }
};

class Coffe : virtual public Drinks {
public:
    Coffe(int price) : Drinks(price) {
        printf("Coffe ���캯��\n");
    }

    void drink() {
        printf("Coffe �ȿ���\n");
    }
};

class TeaCoffeMike : public Tea, public Coffe, public Milk {
public:
    TeaCoffeMike(int price) : Drinks(price), Milk(price), Coffe(price), Tea(price) {
        printf("TeaCoffeMike ���캯��\n");
    }

};

int main() {
    TeaCoffeMike teaCoffeMike(12);
    // ���ڶ������̳��游��ʱ ��virtual���Ρ�
    // ����ֻҪ������û����д�游��ķ���������ʱ����ʹ���游��ķ���
    // һ����һ��������д�ˣ��ͻ�Ĭ�ϵ��ø�����д�ķ���
    // ������������д�˸÷��������㱻virtual���Σ��ӻ���ֶ�����
    // teaCoffeMike.drink();
    // ����1�� ͨ������:: ���߱����������ĸ�����ķ���
    teaCoffeMike.Tea::drink();
    // ����2��������д�÷���
    teaCoffeMike.sell();
}