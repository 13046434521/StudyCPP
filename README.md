# StudyCPP

#### ��ʶC++

##### C��C++�ĳ�������

    1. C�еĳ�����α����������ͨ��ָ���޸ġ���C++�еĲ�����

```c
    #include "stdio.h"
    // C�еĳ�����α���������޸�
    int main(){
        const int  name = 1000;
        int * name_p = &name;
        *name_p = 10;
        printf("%d",name);
    }
```

```c++
    #include "iostream"
    
    // C++ �У�����Գ�����ȥȡֵ�ٸ�ֵ �Ĳ�����
    // ��д������
    int main(){
        const int data = 10;
        int * data_p = &data;// �˴�����
        *data_p = 1000;
        printf("%d",data);
    }
```

##### ����

    1. ������������Java�еĴ��������C/C++�еĴ���ַ���޸ĵ���ͬһ���ڴ��е�ֵ

```c++
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
        changeData(&num1,&num2);
        printf("----------����ַ----------\n");
        printf("%d,%d,%p,%p\n",num1,num2,&num1,&num2);
    
        printf("----------������----------\n");
        changeData(num1,num2);
        printf("%d,%d,%p,%p\n",num1,num2,&num1,&num2);
    
    
        // data �� data2 ��ָ��ͬһƬ�ڴ档
        int data = 999;
        int &data2 = data;
        data2 = 200;
    
        printf("%d,%p,%p",data,&data,&data2);
    }
```

    2. �ṹ�������еĲ�����char*���͵ĸ�ֵ������ǿת��char*,����:ISO C++11 does not allow conversion from string literal to 'char *',�Ҳ���delete
    3. �������ã������޸�ֵ�����򱨴�

```c++
    #include "iostream"
    #include "string.h"
    typedef struct Student{
        char* name ;
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
        Xiexun xiexun ={(char *)"лѷ",58};
        change(xiexun);
        printf("����:%s,����:%d\n",xiexun.name,xiexun.age);
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
    void add(int num1,int ,int ,long){
    
    }
    
    int main(){
    int num1 =10;
    add(10,20,30,40);
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
    #include "Student.h"

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
        printf("Student������:%s,%s,%d,%d\n",data,name,data2,age);

    }
    #include "Student.h"
    int main(){
        printf("------------ջ�ռ�------------\n");
        Student student ={(char *)"���޼�",29};
        student.setName((char *)"лѷ");
        student.setAge(50);

        printf("name:%s,age:%d\n",student.getName(),student.getAge());
        printf("------------�ѿռ�------------\n");
        Student* student1 = new Student((char *)"���ʦ̫",60);
        student1->setAge(27);
        student1->setName((char *)"������");
        printf("name:%s,age:%d\n",student1->getName(),student1->getAge());

        delete(student1);
        student1= NULL;
    }
```

##### C++��Ҫ����
##### 1.�Զ��������ռ�
```c++
    #include "stdio.h"
    // �Զ���namespace�������ռ�
    namespace jtl{
    int age;
    char* name;

    void show(char*name,int age){
    printf("name:%s,age:%d\n",name,age);
    }
    }
    using namespace jtl;
    int main(){
    jtl::show((char *)"������",29);

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
    #include "iostream"
    class Student{
    public:
        // :height(height) �ȼ��� this->height=height;
        // ��ʼ���б�
        Student(char *name,int age,int height):height(age),age(height),name(name){
    //        this->age = age;
    //        this->height = height;
    //        this->name = name;
            printf("��������:name:%s,age:%d,height:%d\n",name,age,height);

            // ��̬�����ڴ�,Ϊ����ʾ��������
            this->test = (char *)malloc(1024);
        }

        Student(){
            printf("�ղι��캯��\n");
        }

        // Ĭ�ϵ���:Student(char*name,int age,int height),�ٵ��ñ���
        Student(char* name): Student(name,28,190){
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
        Student *student = new Student((char *)"лѷ",60,180);
        printf("name:%s,age:%d,height:%d\n",student->getName(),student->getAge(),student->getHeight());
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

    #include "iostream"

    class Student {
    public:
        Student() {}

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
    #include "iostream"
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