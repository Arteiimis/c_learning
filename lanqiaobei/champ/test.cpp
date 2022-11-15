#include <iostream>
using namespace std;

int main()
{
    long long int n, k, T, piov = 1, DD = 0, count = 0;
    cin >> n >> k >> T;
    // if (n == 3 && k == 13 && T == 3)
    // {
    //     cout << 17 << endl;
    //     return 0;
    // }
    for (long long int i = 0, step = 0; count < T; i++, step++)
    {
        if ((piov + step) < (k - 1))
        {
            piov += step;
        }
        else
        {
            long long int temp = k - 1 - piov;
            piov = step - temp - 1;
        }
        if (i == 0 || i % n == 0)
        {
            DD += piov;
            count++;
        }
    }

    cout << DD << endl;

    return 0;
}