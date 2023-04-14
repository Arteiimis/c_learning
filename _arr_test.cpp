#include <iostream>
using namespace std;
class point
{
private:
	float x, y;

public:
	void set_point(float a, float b);
	float read_x(void);
	float read_y(void);
	void move(float a, float b);
};
void point::set_point(float a, float b)
{
	x = a;
	y = b;
}
float point::read_x(void)
{
	return x;
}
float point::read_y(void)
{
	return y;
}
void point::move(float a, float b)
{
	x += a;
	y += b;
}

int main(void)
{
	point p1, &p2 = p1;
	p1.set_point(20, 30);
	cout << "x=" << p1.read_x();
	cout << "  y=" << p1.read_y() << endl;
	cout << "x=" << p2.read_x();
	cout << "  y=" << p2.read_y() << endl;
	p2.move(5, 5);
	cout << "x=" << p1.read_x();
	cout << "  y=" << p1.read_y() << endl;
}