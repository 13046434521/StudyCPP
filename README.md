# StudyCPP

#### 初识C++
##### C和C++的常量区别
    1. C中的常量是伪常量。可以通过指针修改。而C++中的不允许
```c
#include "stdio.h"
// C中的常量：伪常量可以修改
int main(){
    const int  name = 1000;
    int * name_p = &name;
    *name_p = 10;
    printf("%d",name);
}
```
```c++
#include "iostream"

// C++ 中，不许对常量进去取值再赋值 的操作。
// 该写法报错
int main(){
    const int data = 10;
    int * data_p = &data;// 此处报错
    *data_p = 1000;
    printf("%d",data);
}
```