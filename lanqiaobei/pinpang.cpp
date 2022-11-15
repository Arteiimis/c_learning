#include <iostream>
#include <cstring>
using namespace std;

int win[62503];
int w, l;

int main()
{
    char s;
    for (int i = 1; cin >> s && s != 'E'; i++)
    {
        if (s == 'W')
            win[i] = 1;
        else
            win[i] = 2;
    }

    for (int i = 1;; i++)
    {
        if (win[i] == 1)
            w++;
        if (win[i] == 2)
            l++;
        if (win[i] == 0)
        {
            cout << w << ":" << l << endl
                 << endl;
            break;
        }
        if (w - l >= 2 || l - w >= 2)
            if (w >= 11 || l >= 11)
            {
                cout << w << ":" << l << endl;
                w = 0;
                l = 0;
            }
    }
    w = 0;
    l = 0;

    for (int i = 1;; i++)
    {
        if (win[i] == 1)
            w++;
        if (win[i] == 2)
            l++;
        if (win[i] == 0)
        {
            cout << w << ":" << l << endl
                 << endl;
            break;
        }
        if (w - l >= 2 || l - w >= 2)
            if (w >= 21 || l >= 21)
            {
                cout << w << ":" << l << endl;
                w = 0;
                l = 0;
            }
    }
    return 0;
}