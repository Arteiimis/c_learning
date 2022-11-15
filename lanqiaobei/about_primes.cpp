#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bitset>
using namespace std;

const int maxn = 1e7 + 10;
bitset<maxn> Pri;          //筛法所需筛表, 0为素数, 1为和数(被筛除)
int Primes[maxn], ptr = 0; //定义欧拉筛法所需数组以及索引

inline bool isPrimes(int n)
{
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n = 1e7, cnt = 0;

    //埃氏筛法
    // for (int i = 2; i <= n / i; i++)
    // {
    //     if (!Pri[i])
    //         for (int j = i * i; j <= n; j += i)
    //             Pri[j] = 1;
    // }

    //欧拉筛法
    for (int i = 2; i <= n; i++)
    {
        if (!Pri[i])
            Primes[++ptr] = i;
        for (int j = 1; Primes[j] * i <= n; j++)
        {
            Pri[Primes[j] * i] = 1;
            if (i % Primes[j] == 0)
                break;
        }
    }

    for (int i = 2; i <= n; i++)
        if (!Pri[i])
            cnt++;
    printf("%d", cnt);

    return 0;
}