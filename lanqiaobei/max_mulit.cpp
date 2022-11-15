#include <bits/stdc++.h>
using namespace std;

string mulit(string s1, string s2)
{
    string str;
    int _s1[10001], _s2[10001], ans[10001];
    int len1 = s1.length();
    int len2 = s2.length();
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
        if (ans[i] > 9)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    int len = len1 + len2;
    while (ans[len] == 0 && len > 1)
    {
        len--;
    }
    for (int i = len; i >= 1; i--)
    {
        str += (char)(ans[i] + '0');
    }

    return str;
}

string trans(int x)
{
    int i = 0, j;
    string p;
    char ch[10], t;
    do{
        ch[i++] = x % 10 + '0';
        x /= 10;
    }while(x);

    ch[i] = '\0';
    for(j = 0, i--; j < i; j++, i--)
    {
        t = ch[j];
        ch[j] = ch[i];
        ch[i] = t;
    }

    return ch;
}



int main()
{
    int n;
    cin >> n;

    

    return 0;
}