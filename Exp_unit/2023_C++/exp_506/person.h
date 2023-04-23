#ifndef PERSON_H
#define PERSON_H

#include <bits/stdc++.h>
using namespace std;

class person
{
private:
    string name;
    string gender;
    int age;

public:
    person(string name = "", string gender = "", int age = 0);

    void setName(string name);
    void setGender(string name);
    void setAge(int age);

    string getName();
    string getGender();
    int getAge();

    void showInfo();
};

person::person(string name, string gender, int age)
{
    this->name = name;
    this->gender = gender;
    this->age = age;
}

void person::setName(string name)
{
    this->name = name;
}

void person::setGender(string gender)
{
    this->gender = gender;
}

void person::setAge(int age)
{
    this->age = age;
}

string person::getName()
{
    return name;
}

string person::getGender()
{
    return gender;
}

int person::getAge()
{
    return age;
}

void person::showInfo()
{
    cout << "Name: " << name << " Gender: " << gender << " Age: " << age << endl;
}

#endif