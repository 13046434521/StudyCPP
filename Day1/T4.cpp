//
// Created by Administrator on 2022/4/21.
//

#include "iostream"
using namespace std;

// ֱ�����ڴ��ַ�ϲ���
void changeData(int * num1,int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    printf("%p,%p\n",num1,num2);
}

// �����ã�������Java������ͬһ�������ڷ������޸Ķ��󣬾ͻ�
void changeData(int &num1,int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
    printf("%p,%p\n",&num1,&num2);
}

int main(){
    int num1 = 100;
    int num2 = 200;
    printf("����ĵ�ֵַ��%p,%p\n",&num1,&num2);

    printf("----------����ַ----------\n");
    changeData(&num1,&num2);
    printf("%d,%d,%p,%p\n",num1,num2,&num1,&num2);

    printf("----------������----------\n");
    changeData(num1,num2);
    printf("%d,%d,%p,%p\n",num1,num2,&num1,&num2);


    // data �� data2 ��ָ��ͬһƬ�ڴ档
    int data = 999;
    // ��data����ȡ��һ������data2
    int &data2 = data;
    data2 = 200;

    printf("%d,%p,%p",data,&data,&data2);
}