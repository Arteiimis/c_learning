#include <bits/stdc++.h>

class point
{
public:
    double x, y;
    point(double x, double y) : x(x), y(y) {}
    point() {}
    friend class distance;
};

class distance
{
public:
    double dis(point a, point b)
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
};

int main()
{
    point a(1, 2), b(3, 4);
    distance d;
    std::cout << d.dis(a, b) << std::endl;

    return 0;
}