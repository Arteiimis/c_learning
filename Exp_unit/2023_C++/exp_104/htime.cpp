#include "htime.h"

string time::output_time()
{
    string s;
    s = to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
    return s;
}

void time::input_time()
{
    cout << "Enter hour: ";
    cin >> hour;
    cout << "Enter minute: ";
    cin >> minute;
    cout << "Enter second: ";
    cin >> second;

    if (second >= 60)
    {
        minute += second / 60;
        second %= 60;
    }
    if (minute >= 60)
    {
        hour += minute / 60;
        minute %= 60;
    }
    if (hour >= 24)
    {
        hour %= 24;
    }
}

int time::output_hour()
{
    return hour;
}

int time::output_minute()
{
    return minute;
}

int time::output_second()
{
    return second;
}
