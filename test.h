#include <bits/stdc++.h>
using namespace std;

vector<int> bigger(int &a, int &b)
{
    if (a < b)
        return {a, b};
    else
        return {b, a};
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << bigger(a, b)[0] << " " << bigger(a, b)[1] << endl;

    return 0;
}   