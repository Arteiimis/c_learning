#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int child[N], temp[N], count = 0;
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        cin >> child[i];
        if (i == 0)
            temp[N - 1] = child[i] / 2;
        else
            temp[i - 1] = child[i] / 2;
    }
    while (s.size() != 1)
    {
        s.clear();
        // for (int i = 0; i < N; i++)
        // {
        //     if (i == 0)
        //         temp[N - 1] = child[i] / 2;
        //     else
        //         temp[i] = child[i - 1] / 2;
        // }
        for (int i = 0; i < N; i++)
        {
            child[i] = child[i] / 2 + temp[i];

            if (child[i] % 2 == 1)
            {
                child[i]++;
                count++;
            }
            if (i == 0)
                temp[N - 1] = child[i] / 2;
            else
                temp[i - 1] = child[i] / 2;

            s.insert(child[i]);
        }
    }

    cout << count << endl;
    return 0;
}