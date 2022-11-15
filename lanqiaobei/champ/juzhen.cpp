#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
    LL int n, k, T, piov = 1, DD = 0, count = 0;
    cin >> n >> k >> T;
    // if (n == 3 && k == 13 && T == 3)
    // {
    //     cout << 17 << endl;
    //     return 0;
    // }
    LL int i = 0, step = 0;
    while(count < T)
    {
        if((piov + step) < (k - 1))
        {
            piov += step;
        }
        else
        {
            LL int temp = k - 1 - piov;
            piov = step - temp - 1;
        }
        if(i % n == 0)
        {
            DD += piov;
            count++;
        }
        i++;
        step++;
    }

    cout << DD << endl;

    return 0;
}