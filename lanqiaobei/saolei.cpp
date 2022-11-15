#include <iostream>
using namespace std;

int dp[101][101];

int main()
{
    int n, m;
    char tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tmp;
            if(tmp == '*')
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(dp[i][j] == 1)
            {
                printf("*");
            }
            else
            {
                printf("%d", dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1] + dp[i][j - 1] + dp[i][j + 1] + dp[i + 1][j - 1] + dp[i + 1][j] + dp[i + 1][j + 1]);
            }
        }
        printf("\n");
    }
    return 0;
}