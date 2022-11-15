#include <bits/stdc++.h>
using namespace std;

bool is_ture_year(int time)
{
    int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, m, d;
    year = time / 10000;
    m = time % 10000 / 100;
    d = time % 100;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        a[1] = 29;
        if (d > 0 && d < a[m - 1] && m > 0 && m < 12)
            return true;
        else
            return false;
    }
    else
    {
        if (d > 0 && d <= a[m - 1] && m > 0 && m <= 12)
            return true;
        else
            return false;
    }
}

int main()
{
    int N;
    int sign1 = 0, sign2 = 0;
    int ans1 = 0, ans2 = 0;
    cin >> N;

    for (N++; N < 89991231; N++)
    {
        if (sign1 == 0)
        {
            for (int i = 0, j = 7; i < 4; i++, j--)
            {
                string _N = to_string(N);
                if (_N[i] != _N[j])
                    break;
                if (i == 3 && is_ture_year(N))
                {
                    sign1 = 1;
                    ans1 = N;
                    break;
                }
            }
        }
        for (int i = 0, j = 7; i < 4; i++, j--)
        {
            string _N = to_string(N);
            if (_N[i] != _N[j])
                break;
            if (_N[0] == _N[2] && _N[1] == _N[3] && _N[4] == _N[6] && _N[5] == _N[7] && _N[3] == _N[4] && is_ture_year(N))
            {
                sign2 = 1;
                ans2 = N;
                break;
            }
        }
        if (sign1 == 1 && sign2 == 1)
            break;
    }
    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}