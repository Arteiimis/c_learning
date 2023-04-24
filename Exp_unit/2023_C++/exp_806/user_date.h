#ifndef USER_DATE_H
#define USER_DATE_H

#include "date.h"

class user_date : date
{
public:
    user_date(int y, int m, int d) : date()
    {
        set_date(y, m, d);
    }
    bool operator==(user_date &d);
    bool operator!=(user_date &d);
    bool operator>(user_date &d);
    bool operator<(user_date &d);
    bool operator>=(user_date &d);
    bool operator<=(user_date &d);
};

bool user_date::operator==(user_date &d)
{
    if (get_year() == d.get_year() && get_month() == d.get_month() && get_day() == d.get_day())
        return true;
    else
        return false;
}

bool user_date::operator!=(user_date &d)
{
    if (get_year() != d.get_year() || get_month() != d.get_month() || get_day() != d.get_day())
        return true;
    else
        return false;
}

bool user_date::operator>(user_date &d)
{
    if (get_year() > d.get_year())
        return true;
    else if (get_year() == d.get_year() && get_month() > d.get_month())
        return true;
    else if (get_year() == d.get_year() && get_month() == d.get_month() && get_day() > d.get_day())
        return true;
    else
        return false;
}

bool user_date::operator<(user_date &d)
{
    if (get_year() < d.get_year())
        return true;
    else if (get_year() == d.get_year() && get_month() < d.get_month())
        return true;
    else if (get_year() == d.get_year() && get_month() == d.get_month() && get_day() < d.get_day())
        return true;
    else
        return false;
}

bool user_date::operator>=(user_date &d)
{
    if (get_year() > d.get_year())
        return true;
    else if (get_year() == d.get_year() && get_month() > d.get_month())
        return true;
    else if (get_year() == d.get_year() && get_month() == d.get_month() && get_day() > d.get_day())
        return true;
    else if (get_year() == d.get_year() && get_month() == d.get_month() && get_day() == d.get_day())
        return true;
    else
        return false;
}

bool user_date::operator<=(user_date &d)
{
    if (get_year() < d.get_year())
        return true;
    else if (get_year() == d.get_year() && get_month() < d.get_month())
        return true;
    else if (get_year() == d.get_year() && get_month() == d.get_month() && get_day() < d.get_day())
        return true;
    else if (get_year() == d.get_year() && get_month() == d.get_month() && get_day() == d.get_day())
        return true;
    else
        return false;
}

#endif