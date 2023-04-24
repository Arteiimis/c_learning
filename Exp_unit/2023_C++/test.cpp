#include <string.h>
#include <iostream>
using namespace std;

class MyString 
{ 
    char *ptr;
public :
    MyString(char *s)
    {
        ptr = new char[strlen(s) + 1];
        strcpy(ptr, s);
    }
    ~MyString()
    {
        delete [] ptr;
    }
    void print()
    {
        cout << ptr << endl;
    }
    MyString &operator=(const MyString &s);
};

MyString &MyString::operator=(const MyString &s) //重载“=”运算符
{ 
    if (this == &s) 
        return *this;  //当用“ob1=ob1;”时，直接返回
    delete[] ptr; //释放被赋值对象的空间
    ptr = new char[strlen(s.ptr) + 1]; //重新为被赋值对象分配空间
    strcpy(ptr, s.ptr);
    return *this;
}

int main()
{
    MyString p1("chen");
    {
        MyString p2("    ");
        p2 = p1;
        p2.print();
    }
    p1.print();
}