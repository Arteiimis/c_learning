#include <iostream>
#include <vector>
using namespace std;

void get_next(string p, vector<int> &next)\
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < p.size() - 1)
    {
        if(j == -1 || p[i] == p[j])
        {
            next[++i] = ++j;
        }
        else
        {
            j = next[j];
        }
    }
}

int KMP(string T, string P)
{
    int i = 0, j = 0;
    vector<int> next(T.size());
    get_next(P, next);
    while(j == -1 || (i < T.size() && j < P.size()))
    {
        if(j == -1 || T[i] == P[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }

    return j == P.size() ? i - j : -1;
}

int main()
{
    string T = "ababbbabaab";
    string P = "abaab";
    cout << KMP(T, P) << endl;

    return 0;
}