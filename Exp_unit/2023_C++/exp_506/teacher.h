#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"

class teacher : public person
{
private:
    string collage;
    string major;
    string education;
    string degree;
    string title;
    int teachingYears;

public:
    teacher(
            string name = "", 
            string gender = "", 
            int age = 0, 
            string collage = "", 
            string major = "", 
            string education = "", 
            string degree = "", 
            string title = "", 
            int teachingYears = 0
            );
    void setCollage(string collage);
    void setMajor(string major);
    void setEducation(string education);
    void setDegree(string degree);
    void setTitle(string title);
    void setTeachingYears(int teachingYears);

    string getCollage();
    string getMajor();
    string getEducation();
    string getDegree();
    string getTitle();
    int getTeachingYears();

    void showInfo();
};

teacher::teacher(
    string name,
    string gender,
    int age,
    string collage,
    string major,
    string education,
    string degree,
    string title,
    int teachingYears)
{
    this->setName(name);
    this->setGender(gender);
    this->setAge(age);
    this->collage = collage;
    this->major = major;
    this->education = education;
    this->degree = degree;
    this->title = title;
    this->teachingYears = teachingYears;
}

void teacher::setCollage(string collage)
{
    this->collage = collage;
}

void teacher::setMajor(string major)
{
    this->major = major;
}

void teacher::setEducation(string education)
{
    this->education = education;
}

void teacher::setDegree(string degree)
{
    this->degree = degree;
}

void teacher::setTitle(string title)
{
    this->title = title;
}

void teacher::setTeachingYears(int teachingYears)
{
    this->teachingYears = teachingYears;
}

string teacher::getCollage()
{
    return collage;
}

string teacher::getMajor()
{
    return major;
}

string teacher::getEducation()
{
    return education;
}

string teacher::getDegree()
{
    return degree;
}

string teacher::getTitle()
{
    return title;
}

int teacher::getTeachingYears()
{
    return teachingYears;
}

void teacher::showInfo()
{
    cout << "Name: " << getName() << " Gender: " << getGender() << " Age: " << getAge() << endl;
    cout << "Collage: " << collage << " Major: " << major << " Education: " << education << " Degree: " << degree << " Title: " << title << " TeachingYears: " << teachingYears << endl;
}

#endif