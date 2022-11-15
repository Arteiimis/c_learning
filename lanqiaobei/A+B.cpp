#include <bits/stdc++.h>
using namespace std;

string add(string s1, string s2)
{
    string str;
    int len1 = s1.length();
    int len2 = s2.length();

    if(len1 < len2)
    {
        for (int i = 1; i <= len2 - len1; i++)
           s1 = "0" + s1;
    }
    else
    {
        for (int i = 1; i <= len1 - len2; i++)
           s2 = "0" + s2;
    }
    len1 = s1.length();
    int upper = 0, temp;
    for (int i = len1 - 1; i >= 0; i--)
    {
        temp = s1[i] - '0' + s2[i] - '0' + upper;
        upper = temp / 10;
        temp = temp % 10;
        str = (char)(temp + '0') + str;
    }
    if (upper != 0)
        str = (char)(upper + '0') + str;

    return str;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << add(s1, s2) << endl;
    return 0;
}