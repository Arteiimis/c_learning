#include <bits/stdc++.h>
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int money = 200;              //定义最大金额
const int num = 5;                  //五个硬币
int type[num] = {1, 5, 10, 25, 50}; //五种面值
int Min[money];
int Min_Path[money];

void solve()
{
    for (int i = 0; i < money; i++)
        Min[i] = INT_MAX;
    Min[0] = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = type[i]; j < money; j++)
        {
            if (Min[j] > (Min[j - type[i]] + 1))
            {
                Min[j] = Min[j - type[i]] + 1;
                Min_Path[j] = type[i];
            }
        }
    }
}
void print(int *Min_Path, int s)
{
    while (s)
    {
        printf("%d ", Min_Path[s]);
        s -= Min_Path[s];
    }
}
int main()
{
    fio int s;
    solve();
    while (cin >> s)
    {
        cout << Min[s];
        print(Min_Path, s);
    }
}
