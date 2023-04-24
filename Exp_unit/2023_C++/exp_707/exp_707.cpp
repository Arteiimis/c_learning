#include <bits/stdc++.h>
using namespace std;

class process
{
public:
    virtual void print() = 0;
};

class person : public process
{
protected:
    string name;
    int age;
    string gender;

public:
    person(string n, int a, string g) : name(n), age(a), gender(g) {}
    void print()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "gender: " << gender << endl;
    }
};

class student : public person
{
protected:
    string id;
    string major;

public:
    student(string n, int a, string g, string i, string m) : person(n, a, g), id(i), major(m) {}
    void print()
    {
        person::print();
        cout << "id: " << id << endl;
        cout << "major: " << major << endl;
    }
};

int main()
{
    // 定义 process 指针变量调用 person 对象及 student 对象
    process *p;
    person p1("Tom", 20, "male");
    student s1("Jerry", 18, "male", "20210001", "Computer Science");
    p = &p1;
    p->print();
    cout << endl;
    p = &s1;
    p->print();
    return 0;
}