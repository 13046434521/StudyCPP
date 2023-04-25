//
// Created by Administrator on 2022/4/21.
//

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
    printf("最初的地址值：%p,%p\n",&num1,&num2);

    printf("----------传地址----------\n");
    changeData(&num1,&num2);
    printf("%d,%d,%p,%p\n",num1,num2,&num1,&num2);

    printf("----------传引用----------\n");
    changeData(num1,num2);
    printf("%d,%d,%p,%p\n",num1,num2,&num1,&num2);


    // data 和 data2 都指向同一片内存。
    int data = 999;
    // 给data变量取了一个别名data2
    int &data2 = data;
    data2 = 200;

    printf("%d,%p,%p",data,&data,&data2);
}