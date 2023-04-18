#ifndef _POINT_H
#define _POINT_H

#include <bits/stdc++.h>
#define M_PI acos(-1)

class point
{
public:
    double x, y;
    point(double x, double y) : x(x), y(y) {}
    point() {}
    friend class distance;
};

class circle : public point
{
public:
    double r;
    circle(double x, double y, double r) : point(x, y), r(r) {}
    circle() {}

    void inputCircle();
    void outputCircle();
};

void circle::inputCircle()
{
    std::cout << "Input x(cm): ";
    std::cin >> x;
    std::cout << "Input y(cm): ";
    std::cin >> y;
    std::cout << "Input r(cm): ";
    std::cin >> r;
}

void circle::outputCircle()
{
    std::cout << "Circumference: " << 2 * M_PI * r << "cm" << std::endl;
    std::cout << "Area: " << M_PI * r * r << "cm^2" << std::endl;
}

#endif