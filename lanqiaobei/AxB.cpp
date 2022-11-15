#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    char s1[10001], s2[10001];
    int _s1[10001], _s2[10001], ans[10001];
    cin >> s1 >> s2;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 1; i <= len1; i++)
    {
        _s1[i] = s1[len1 - i] - '0';
    }
    for (int i = 1; i <= len2; i++)
    {
        _s2[i] = s2[len2 - i] - '0';
    }
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            ans[i + j - 1] += _s1[i] * _s2[j];
        }
    }
    for (int i = 1; i < len1 + len2; i++)
    {
        if(ans[i] > 9)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    int len = len1 + len2;
    while(ans[len] == 0 && len > 1)
    {
        len--;
    }
    for(int i = len; i >= 1; i--)
    {
        cout << ans[i];
    }

    return 0;
}