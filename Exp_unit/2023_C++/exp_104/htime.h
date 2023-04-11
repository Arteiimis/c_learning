#ifndef HTIME_H
#define HTIME_H

#include <bits/stdc++.h>
using namespace std;

class time
{
private:
    int hour;
    int minute;
    int second;
    time(int h, int m, int s): hour(h), minute(m), second(s) {}

public:
    time(): hour(0), minute(0), second(0) {}
    string output_time();
    void input_time();
    int output_hour();
    int output_minute();
    int output_second();
};

#endif