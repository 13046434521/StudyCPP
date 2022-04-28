# StudyCPP

#### ��ʶC++

##### C��C++�ĳ�������

    1. C�еĳ�����α����������ͨ��ָ���޸ġ���C++�еĲ�����

```c
    #include
"stdio.h"
// C�еĳ�����α���������޸�
int main(){
const int name = 1000;
int * name_p = &name;
*name_p = 10;
printf("%d", name);
}
```

```c++
    #include
"iostream"

// C++ �У�����Գ�����ȥȡֵ�ٸ�ֵ �Ĳ�����
// ��д������
int main(){
const int data = 10;
int * data_p = &data;// �˴�����
*data_p = 1000;
printf("%d", data);
}
```

##### ����

    1. ������������Java�еĴ��������C/C++�еĴ���ַ���޸ĵ���ͬһ���ڴ��е�ֵ

```c++
    #include
"iostream"
using namespace std;

// ֱ�����ڴ��ַ�ϲ���
void changeData(int * num1, int *num2){
int temp = *num1;
*num1 = *num2;
*num2 = temp;
printf("%p,%p\n", num1, num2);
}

// �����ã�������Java������ͬһ�������ڷ������޸Ķ��󣬾ͻ�
void changeData(int &num1, int &num2){
int temp = num1;
num1 = num2;
num2 = temp;
printf("%p,%p\n", &num1, &num2);
}

int main(){
int num1 = 100;
int num2 = 200;
changeData(&num1, &num2);
printf("----------����ַ----------\n");
printf("%d,%d,%p,%p\n", num1, num2, &num1, &num2);

printf("----------������----------\n");
changeData(num1, num2);
printf("%d,%d,%p,%p\n", num1, num2, &num1, &num2);


// data �� data2 ��ָ��ͬһƬ�ڴ档
int data = 999;
int &data2 = data;
data2 = 200;

printf("%d,%p,%p", data, &data, &data2);
}
```

    2. �ṹ�������еĲ�����char*���͵ĸ�ֵ������ǿת��char*,����:ISO C++11 does not allow conversion from string literal to 'char *',�Ҳ���delete
    3. �������ã������޸�ֵ�����򱨴�

```c++
    #include
"iostream"
#include
"string.h"
typedef struct Student{
char* name;
int age;
} Xiexun;

// ISO C++11 does not allow conversion from string literal to 'char *'
// char * ����ǿת�� char * ���Ҳ���delete
void change(Student& student){
student.name =(char *) "���޼�";// ���� delete(student.name);
student.age = 29;
}

//�������ã��޷��޸�
// student������ݲ��ܸģ�student����Ҳ���ܸ�ֵΪ���Student
//void changeConst(const Student& student){
//    student.name = "������";// ����д��
//    student.age = 27;// ����д��
//}
int main(){
Xiexun xiexun ={
(char *)"лѷ", 58
};
change(xiexun);
printf("����:%s,����:%d\n", xiexun.name, xiexun.age);
//    changeConst(xiexun);
//    printf("����:%s,����:%d\n",xiexun.name,xiexun.age);

return 0;
}
```

    4. C����û�к������أ�C++�к�������
    5. C++�������Ը�Ĭ��ֵ���������صĺ����͸�Ĭ��ֵ�ĺ������׳��ֶ�����

```c++
    void add(int num1, int num2){

}

void add(int num1 =100, int num2=200, int num3=300){

}

int main(){
int num1 = 1;
int num2 = 2;

// �����������������������ط���,Ҳ��������Ĭ��ֵ�����ط���
// ����������֪�������������������ط���������������Ĭ��ֵ�����ط�����ǰ����������ֵ��������ΪĬ��ֵ�ķ���
// ������
add(num1, num2);
}
```

    6. C++�п�������ռλ��������û�����壬���Ϊ��δ����������

```c++
    // ǰ�ڿ�����ֻ�õ���num1������3������������ռλ
// ���е��÷���4�����������봫
// ���������Ҫ�������ܣ��õ����������������޸�
void add(int num1, int, int, long){

}

int main(){
int num1 =10;
add(10, 20, 30, 40);
}
```

    7. ����������������.hͷ�ļ����.cpp��ִ���ļ�
    8. .hͷ�ļ�������������.cpp�ļ�����дʵ��
    9. new �ڶ��п��ٿռ䣬delete �����ͷŶ��п��ٵĶ���
    10. class�е�public�����������ģ�private��˽�е�
    11. cpp��ʵ�����з�����ʱ����Ҫ::  ����:Student::getAge();
    12. ʵ�ֵ�ʱ��ͨ��this->�������Լ����е����Ժͷ���
    13. exe�ļ����ɵ�ʱ����Ҫ#set(CMAKE_EXE_LINKER_FLAGS "-static")����target_link_libraries (StudyCPP -static) ����ʱ��Ӿ�̬��

```c++
    class Student {
public:
Student(char *data1, int data2);

private:
char *name;
int age;
public:
char *getName();

int getAge();

void setName(char *name);

void setAge(int age);
};
#include
"Student.h"

int Student::getAge() {
return this->age;
}

char *Student::getName() {
return this->name;
}

void Student::setAge(int age) {
this->age = age;
}

void Student::setName(char *name) {
this->name = name;
}

Student::Student(char *data, int data2) : name(data), age(data2) {
printf("Student������:%s,%s,%d,%d\n", data, name, data2, age);

}
#include
"Student.h"
int main(){
printf("------------ջ�ռ�------------\n");
Student student ={ (char *)"���޼�", 29 };
student.setName((char *)"лѷ");
student.setAge(50);

printf("name:%s,age:%d\n", student.getName(), student.getAge());
printf("------------�ѿռ�------------\n");
Student* student1 = new Student((char *)"���ʦ̫", 60);
student1->setAge(27);
student1->setName((char *)"������");
printf("name:%s,age:%d\n", student1->getName(), student1->getAge());

delete(student1);
student1= NULL;
}
```

##### C++��Ҫ����

##### 1.�Զ��������ռ�

```c++
    #include
"stdio.h"
// �Զ���namespace�������ռ�
namespace jtl{
int age;
char* name;

void show(char*name, int age){
printf("name:%s,age:%d\n", name, age);
}
}
using namespace jtl;
int main(){
jtl::show((char *)"������", 29);

return 0;
}
```

##### 2.���캯������������

    1. �����ڶ��л���ջ�д������󣬶�����ù��캯����
    2. C++����Ĭ���޲ι��캯��
    3. ���캯�����ù��캯����������:(����)����ֵ
    4. ��ʼ���б��൱�ڸ�ֵ��:height(height) �ȼ��� this->height=height;
    5. �������������޲Σ�����~��������
    6. ջ�д����Ķ��󣬻��Զ�������������
    7. ����ͨ�� new �����Ķ��󣬱���delete��delete�������������

```c++
    //���캯��
#include
"iostream"
class Student{
public:
// :height(height) �ȼ��� this->height=height;
// ��ʼ���б�
Student(char *name, int age, int height):height(age), age(height), name(name){
//        this->age = age;
//        this->height = height;
//        this->name = name;
printf("��������:name:%s,age:%d,height:%d\n", name, age, height);

// ��̬�����ڴ�,Ϊ����ʾ��������
this->test = (char *)malloc(1024);
}

Student(){
printf("�ղι��캯��\n");
}

// Ĭ�ϵ���:Student(char*name,int age,int height),�ٵ��ñ���
Student(char* name): Student(name, 28, 190){
printf("һ���ι��캯��\n");
}

char *getName() const {
return name;
}

int getAge() const {
return age;
}

int getHeight() const {
return height;
}

// ջ�п��ٵĶ��󣬳�ջʱ�Զ�������������
// ���п��ٵĶ���delete(����)ʱ������������. free(����)���������������
~Student(){
printf("��������?\n");
// �ͷŶ�̬���ٵ��ڴ�
if (test){
free(test);
test =NULL;
}
}

private:
char *name;
int age;
int height;
char*test;
};

int main(){
Student stu ((char *)"���޼�");
Student *student = new Student((char *)"лѷ", 60, 180);
printf("name:%s,age:%d,height:%d\n", student->getName(), student->getAge(), student->getHeight());
delete(student);
student =NULL;
}
```

##### 3.��������

> 1. C�����С�malloc��free�Ƕ�Ӧ�ġ�������ù��캯��������������
> 2. C++�С�new �� delete�Ƕ��εġ�����ù��캯��������������

##### 4.�������캯��

    1. ����=���� ���ֲ�������õ��������캯����
    2. ָ��=ָ�� ���ֲ�����ʵ����������ָ��ָ��ͬһ���ڴ棬������ÿ������캯����
    3. Stu stu1 = Stu()/Stu stu1(); Stu stu2=stu1; ���ֲ������ȵ����Զ��忽�����캯��
    4. Stu stu1 = Stu()/Stu stu1();Stu stu2;stu2=stu1; ���ֲ��������Ĭ�Ϲ��캯����

```c++
    // 4.�������캯��
//  ����=���� ִ�п������캯��
//  ָ��=ָ�� ��ִ�п������캯��

#include
"iostream"

class Student {
public:
Student() {
}

Student(Student &student) {
printf("�������캯��:%p\n", &student);
this->name = student.name;
this->height = student.age;
this->age = student.height;
}

Student(char *name, int age, int height) : name(name), age(age), height(height) {
printf("���캯��\n");
}

char *getName() const {
return name;
}

int getHeight() const {
return height;
}

int getAge() const {
return age;
}

private:
char *name;
int age;
int height;
};

// �������캯��
int main() {

printf("*******************���д�������:ָ��ָ���ڴ��ַ***********************\n");
printf("*******************���д�������:��ִ�п������캯��***********************\n");
// ����ָ��ָ��ͬһ���ڴ棬���Բ�ִ�п������캯��
Student *stu = new Student((char *) "���޼�", 29, 180);
Student *stu1 = stu;// stu1��stuָ��ͬһ���ڴ棬
//    stu = nullptr;
printf("student:%p\n", stu);
printf("student:%p\n", stu1);

printf("name:%s,age:%d,height:%d\n", stu1->getName(), stu1->getAge(), stu1->getHeight());

printf("\n*******************ջ�д�������:�����������캯��***********************\n");
// ��ִ���Զ��忽�����캯��
Student student((char *) "лѷ", 60, 190);
Student student1 = student;
printf("student:%p\n", &student);
printf("name:%s,age:%d,height:%d\n", student1.getName(), student1.getAge(), student1.getHeight());


printf("\n*******************ջ�д�������:Ĭ�Ͽ������캯��***********************\n");
// ��ִ��Ĭ�Ͽ������캯��
Student student2;
student2 = student;

printf("student:%p\n", &student);
printf("name:%s,age:%d,height:%d\n", student2.getName(), student2.getAge(), student2.getHeight());
}
```

##### ����ָ�룬ָ�볣��������ָ�볣��

    1. ԭ�򣺵�һ�������Ըı䣬�ڶ������Ա䡣
    2. ����ָ�룺const int*p: ָ�����ε��ڴ��еĳ����������޸ġ�ָ��ָ���λ�ÿ����޸�
    3. ָ�볣����int*p const: ָ��ָ���λ�ò����޸ģ�ָ��ָ����ڴ��еĳ�����ֵ�����޸ġ�
    4. ����ָ�볣����const int*p const: ʲô�������޸�

```c++
    // 5. ����ָ�룺const int * p;
//    ָ�볣��: int * const p;
//    ����ָ�볣����const int * const p;
//
#include
"iostream"
int main(){
printf("*******************����ָ�룺***********************\n");
int num1 = 200;
int num2 = 100;

const int* p1 = &num1;
p1 = &num2;
//    *p1 = 300; ����ָ�룺�����޸�ָ��ָ��ĵ�ַ�еĳ���ֵ�������޸�ָ��ָ��ĵ�ַ

printf("\n*******************ָ�볣����***********************\n");
int* const p2 = &num1;
//    p2 = &num2; ָ�볣��:�����޸�ָ��ָ����ڴ��ַ�������޸�ָ��ָ����ڴ��ַ�еĳ���
*p2 = 300;
printf("\n*******************����ָ�볣����***********************\n");
const int*const p3 = &num1;
// ����ָ�볣����ָ��ָ��ĵ�ַ��ָ��ָ��ĵ�ַ�е�ֵ�����ܸı�
//    p3 = &num2;
//    p3 = nullptr;
//    *p3 = 300;
}
```
##### C++ǳ���������
    1. ǳ������class�ĳ�Ա��������ж��д����ı�����ǳ�����ᵼ�£�����ǰ�Ķ���Ϳ�����Ķ�������ԣ�ָ��ͬһ�����ڴ档�ͷ�ʱ������ظ��ͷ�
    2. ��������еı��������ٴδ�����ͬʱ�����ݿ������´������ڴ��С�������������ı�����ָ��ͬһ���ڴ档
    3. Student getStudent(Student stu){} �������ÿ������캯����stu��ͨ���������캯�����������Ķ���
    4. Ĭ�ϵĿ������캯��������ǳ����
    5. �������캯���У��Ὣ����Ĳ���������this�У�����this��
    6. class�ĳ�Ա�������ڶ����ϴ����ģ�������д�������캯��
```c++
#include "iostream"
class Student{
private:
    char * name;
    int age;
    int height;
public:
    Student(const Student& student){
        printf("�������캯��:������ַ:%p,this��ַ:%p\n",&student,this);
    }

    Student(char *name, int age=10, int height=180) : name(name), age(age), height(height) {
        printf("�вι��캯��:%p\n",this);
    }
    Student(){
        printf("�޲ι��캯��:��ַ:%p\n",this);
    }
    ~Student(){
        printf("��������:%p\n",this);
    }
};

Student getStudent(char* name){
    Student student(name);

    printf("getStudent��ַ:%p\n",&student);

    return student;
}
// ��ִ�п������캯��
Student getStudent1(Student stu){
    stu.name =(char *) "���޼�";
    printf("getStudent��ַ:%p\n",&stu);
    return stu;
}
int main(){
    Student student;
    printf("main:%p\n",&student);
    // �������ÿ������캯����getStudent�е�stu�ʹ����student����ͬһ������
    Student stu =  getStudent1(student);
    Student student1 = getStudent((char *)"���޼�") ;

    printf("main:%p\n",&student1);
}
/*
 *�޲ι��캯�� STU1000
 * main STU1000
 * �вι��캯�� STU2000
 * getStudent STU2000
 * �������캯�� STU2000,STU3000
 * �������� STU2000
 * main STU3000
 * �������� STU3000
 * �������� STU1000
 */
```
##### ��Ԫ��������Ԫ��
##### 1. �ɱ����
    1.����ͷ�ļ� #include "stdarg.h"//֧�ֿɱ����ͷ�ļ�
    2. va_List va_list; //�����ɱ�����б�
    3. va_start(va_list,count); //va_listָ��ɱ����ͷָ�롣
    4. va_arg(va_list,int); //ȡ���ɱ���������ݣ�����1���ɱ�����б�����2��ȡ��������
    5. va_end(va_list);// ���ɱ�����б��ÿ�
```c++
//
// Created by jiatianlong on 2022/4/24.
// 1. �ɱ����
//
#include "stdarg.h"//֧�ֿɱ����ͷ�ļ�
#include "iostream"
void getData(int count ,...){
    va_list  vaList;
    // ��vaListָ��ɱ����ͷ��ַ
    va_start(vaList,count);

    for (int i = 0; i < count; ++i) {
        // va_arg :ȡ����ǰָ��ָ��Ŀɱ����
        // ��һ���������ɱ�����б�
        // �ڶ�������������
        printf("%d\n", va_arg(vaList,int));
    }

    //vaList�ÿ�
    va_end(vaList);
}


int main(){
    getData(10,8,9,"1","2",3.0f);
}

```
##### 2. ��̬�����뾲̬����
    1. ��̬��������̬��������ʱ����ʹ��static
    2. ��̬����ʵ��ʱ������ ����::��������int Person::age = 20; 
    3. ��̬����ʵ��ʱ���������� ����::��������int Person::age = 20; 
```c++
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

// ��̬����ʵ��
void Person::staticUpDate() {
    age+=10;
}
// ��̬������ֵ
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
```

##### 3. thisָ�븳ֵ
    1. thisָ����һ��ָ�볣����
    2. ���ԣ�����ͨ��this�޸Ķ������Ե�ֵ
    3. ���ǣ�����ͨ��this�޸ģ�thisָ��ĵ�ַ

##### 4. ��Ԫ����
    1. ��A���м���˽�����ԣ���B����һ�������Ĳ�������A��// void upDateHeight(Student* student,int age,int height);//����Ԫ���������ܷ���Student��˽�г�Ա
    2. �����������B�еķ����޷�������A �е�˽�б�����
    3. �����friend�ؼ��ֽ������Ρ��ͱ������Ԫ������// friend void upDateHeight(Student* student,int age,int height);//��Ԫ���������Է���Student��˽�г�Ա
    4. ��Ԫ��������ʱ�����ü�����:: // void upDateAge(Student* student,int age){}
```c++
//
// Created by jiatianlong on 2022/4/26.
// ��Ԫ����
//
#include "iostream"
class Student{
private:
    int age;
    int height;

public:
    int getAge() const {
        return age;
    }

    int getHeight() const;

    friend void upDateHeight(Student* student,int age,int height);
};

void upDateAge(Student* student,int age){
    //��ôд�Ǵ�ģ���Ϊage��˽�еġ��޷�����
    //student->age=age;
}

// ��Ԫ���������Է���Student�е�˽�ж���
// ����Ҫ������
void upDateHeight(Student* student,int age,int height){
    student->age = age;
    student->height=height;
}

int Student::getHeight() const {
    return height;
}

int main(){
    Student student;
    upDateHeight(&student,18,180);
    printf("age %d,height %d\n",student.getAge(),student.getHeight());
}
```
##### 5.���������༰��ط���
    1. .h �е��ļ������忽��������ʵ���ļ��У�.cpp�ļ���
    2. .h�ļ��еĺ궨����Ϊ�˷�ֹѭ������ġ�
```c++
#ifndef PIG_H
#define PIG_H

#include "iostream"
using namespace std;


class Pig {
private:
    char * name;
    int age;
public:
    static int height;
    // ���캯��
    Pig();
    Pig(char *name);
    Pig(char *name,int age);

    // �������캯��
    Pig(const Pig& pig);

    // ��������
    ~Pig();

    // ������������
    void setName(char *name);
    void setAge(int age);
    void setPig(Pig &pig);

    //��������
    void showPigInfo() const;//

    char *getName();
    int getAge();

    // ��̬����
    static void Update(Pig* pig);
    // ��Ԫ����
    friend void friendPig(Pig pig,char*name,int age);
};


#endif //STUDYCPP_PIG_H
//
// Created by jiatianlong on 2022/4/27.
//
// ��ķ���ʵ�֣���Ҫ��  ����::
// ��ͨ����: ����ֵ ����::
// ��̬����: ����ͨ����һ��������Ҫ��static
// ��Ԫ����: ����Ҫ�� ����::

#include "Pig.h"

Pig::Pig() {
    cout << "���캯��:��ַ��"<<this<<  endl;
}

Pig::Pig(char *name) {
    this->name = name;
    cout << "���캯��:һ������:��ַ��"<<this<< " name:" << name << endl;
}

Pig::Pig(char *name, int age) : name(name), age(age) {
    cout << "���캯��:��������:��ַ��"<<this<< " name:" << name << " age:" << age << endl;
}

Pig::Pig(const Pig &pig) {
    cout << "�������캯��:�������pig��ַ��" << &pig << " �¶���this��ַ:" << this << endl;
}

void Pig::showPigInfo() const {
    cout << "��ͨ����:showPigInfo:this��ַ��" << this <<" name:"<<name<<" age:"<<age<< endl;
}

void Pig::setName(char *name) {
    this->name = name;
    cout << "��ͨ����:setName:this��ַ��" << this << endl;
}

void Pig::setAge(int age) {
    this->age =age;
    cout << "��ͨ����:setAge:this��ַ��" << this << endl;
}

void Pig::setPig(Pig &pig) {
    //this = pig; ����д����this�Ǹ�ָ�볣��
    this->name = pig.name;
    this->age = pig.age;

    cout << "��ͨ����:setPig:pig��ַ:" << &pig << " this��ַ��" << this << endl;
}

int Pig::getAge() {
    cout<<"��ͨ������getAge:this��ַ��"<<this<< " age:"<<age<<endl;
    return this->age;
}

char *Pig::getName() {
    cout<<"��ͨ������getName:this��ַ��"<<this<< " name:"<<name<<endl;
    return this->name;
}

void Pig::Update(Pig *pig) {
    cout << "��̬����:�޷�����this����������ַ��" << pig << endl;
}

int Pig::height = 180;

void friendPig(Pig pig, char *name, int age) {
    pig.name = name;
    pig.age = age;
    cout << "��Ԫ����:���Ե������˽�����ԣ���������ַ��" << &pig <<" name��"<<pig.name<<" age��"<<pig.age<< endl;
}


Pig::~Pig() {
    cout << "��������:�����ַ��" << this << endl;
}


#include "Pig.h"

int main(){
    Pig pig;
    Pig* pig_p = new Pig((char*)"лѷ",50);

    Pig pig1 = pig;
    pig1.setName((char *)"���޼�");
    pig1.setAge(20);
    pig1.getName();
    Pig::Update(pig_p);

    pig1.showPigInfo();

    pig.setPig(pig1);
    pig.showPigInfo();

    friendPig(pig1,(char *)"������",18);
    pig1.getName();
    pig1.showPigInfo();
    delete(pig_p);
}
```
##### 6.��Ԫ��
    1. ����A��������BΪ�Լ�����Ԫ��
    2. ��B�е�����Aʱ�����Ե�����A��˽�г�Ա
```c++
//
// Created by jiatianlong on 2022/4/27.
// ��Ԫ��
// ��A�ж�����BΪ��Ԫ��
// ��������B�е��ã���A��˽������

#include "iostream"

using namespace std;
class Student{
private:
    int age;
    int klass;
    friend class Grade;
public:
    void setAge(int age){
        this->age = age;
    }

    int getAge(){
        return this->age;
    }
    void setKlass(int klass){
        this->klass = klass;
    }

    int getKlass(){
        return this->klass;
    }
};

class Grade {
private:

public:
    void setKLass(Student &st, int klass) {
        st.klass = klass;
    };
};

int main(){
    Student student ;
    student.setAge(10);
    Grade grade;
    grade.setKLass(student,20);

    cout<<student.getAge()<<endl;
}
```
##### ��������غͼ̳�
##### 1. ���������
    1. ����Ͷ���֮�䲻��������������
    2. ����ͨ��operator�ؼ��� ��д �������
    3. ���ض��� operator ������ (�������){}; 
    4. Student  operator   +   (Student student1,Student student2){}
    5. ������������������أ���������ı��磤���ַ��Ų����Խ��иò���
```c++
// ���������
#include "iostream"
class Student{
public:
    int age;
    int height;

public:
    Student(){};
    Student(int age,int height):age(age),height(height){}
};

// ����������
Student operator + (Student student1,Student student2){
    Student stu;
    stu.age = student1.age+student2.age;
    stu.height = student1.height+student2.height;
    return stu;
}


int main(){
    Student student1(20,180);
    Student student2(29,174);

    // ��д�˲�����������student�������ִ��+����
    Student studentSet = student1+student2 ;
    std::cout<<studentSet.age<<"---"<<studentSet.height<<std::endl;
}

```
###### C++�̳�
    1. c++��javaһ�����Լ̳У�����java�ǵ��̳У�c++���Լ̳ж������
    2. c++�еļ̳з�Ϊprivate��public��Ĭ����private
    3. ����̳и���ʱ���������У��������ּ̳У����޷����ø����˽������
    4. ����̳и���ʱ���������У��������ּ̳У������Ե��ø���Ĺ�������
    5. ����̳и���ʱ��������֮�⣬private�ļ̳У��޷����ø���Ĺ�������
    6. ����̳и���ʱ��������֮�⣬public�ļ̳У����Ե��ø���Ĺ�������
```c++
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
```
###### �̳�ʱ�����Ķ�����
    1. ����̳ж������ʱ���������ͬʱ��ʵ����ĳ����������ô�ڱ�ĺ����е���ʱ������ֶ�����
    2. Ϊ������ֶ����ԣ�Ҫô������д�����еķ�����Ҫôͨ��  ������::�����߱�������������õ����ĸ������еķ���
```c++
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
```
###### virtual�ؼ��֣������
    1. �游����һ������A����������ͬʱ�̳����游�ࡣ������ͬʱ�̳����������ࡣ���������Aʱ�ͻ���ֶ�����
    2. ����֮ǰ�����Ľ���������������ڸ���̳��游��ʱ��virtual�ؼ�������
    3. �����virtual�ؼ������Σ������ڵ��÷���Aʱ�����ǵ��õ��游��ķ������Ҳ�����ֶ�����
    4. �����ʱ��ĳ��������д�˷���A����ô����.A()���õľ��Ǹ���ķ���A
    5. �����ʱ���������඼��д�˷���A���������Ͳ�֪��������õ��ĸ����е�A����������Ҫ����::A��ָ��������
```c++
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
```