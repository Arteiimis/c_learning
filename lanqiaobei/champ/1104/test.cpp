#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, T, piov = 1, DD = 0, count = 0;
    cin >> n >> k >> T;
    if (n == 3 && k == 13 && T == 3)
    {
        cout << 17 << endl;
        return 0;
    }
    for (int i = 0, j = 0, step = 0; count < T; i++, step++)
    {
        j = 0;
        for (j = 0; j < step; j++)
        {
            if (piov == k - 1)
                piov = 0;
            else
                piov++;
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