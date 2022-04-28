//
// Created by jiatianlong on 2022/4/28.
// C++ �ж�̳�
//
#include "iostream"
class Drinks{
public:
    int price;

    Drinks(int price) : price(price) {
        printf("Drink ���캯��\n");
    }
};
class Tea:public Drinks{
public:
    Tea(int price) : Drinks(price) {
        printf("Tea ���캯��\n");
    }

    void drink(){
        printf("Tea ζ���ܰ�\n");
    }

    void sell(){
        printf("Tea 25��Ǯһ��\n");
    }
};
class Milk:public Drinks{
public:
    Milk(int price) : Drinks(price) {
        printf("Milk ���캯��\n");
    }

    void drink(){
        printf("Milk ζ���е���\n");
    }

    void sell(){
        printf("Milk 10��Ǯһ��\n");
    }
};
class Coffe:public Drinks{
public:
    Coffe(int price) : Drinks(price) {
        printf("Coffe ���캯��\n");
    }

    void drink(){
        printf("Coffe �е��\n");
    }

    void sell(){
        printf("Coffe 15��Ǯһ��\n");
    }
};
class TeaCoffeMike:public Tea,public Coffe,public Milk{
public:
    TeaCoffeMike(int price) : Milk(price), Coffe(price), Tea(price) {
        printf("TeaCoffeMike ���캯��\n");
    }

    void sell(){
        printf("TeaCoffeMike 50��Ǯһ��\n");
    }
};

int main(){
    TeaCoffeMike teaCoffeMike(12);
    // ��������ж�ʵ���˸÷��������Բ���ֱ�ӵ��ã����ֶ�����
    // teaCoffeMike.drink();

    // ����1�� ͨ������:: ���߱����������ĸ�����ķ���
    teaCoffeMike.Coffe::drink();
    // ����2��������д�÷���
    teaCoffeMike.sell();
}