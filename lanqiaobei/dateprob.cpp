#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int res = 0;
    int len = S.length();

    for (int i = 0; i < len; i++)
    {
        int left = 0, right = 0;

        for (int j = i - 1; j >= 0 && S[j] != S[i]; j--)
            left++;
        for (int j = i + 1; j < len && S[j] != S[i]; j++)
            right++;
            
        res += (left + 1) * (right + 1);
    }
    cout << res << endl;

    return 0;
}