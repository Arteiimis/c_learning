#include "teacher.h"
#include "person.h"
using namespace std;

int main()
{
    person p1("张三", "男", 20);
    teacher t1("李四", "女", 30, "计算机学院", "计算机科学与技术", "本科", "硕士", "教授", 10);
    p1.showInfo();
    t1.showInfo();

    return 0;
}