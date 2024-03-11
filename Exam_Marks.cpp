#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

bool subset(int n, int s, int a[])
{
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }
    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }

    if (a[n - 1] <= s)
    {
        bool op1 = subset(n - 1, s - a[n - 1], a);
        bool op2 = subset(n - 1, s, a);
        return dp[n][s] = op1 || op2;
    }
    else
    {
        bool op2 = subset(n - 1, s, a);
        return dp[n][s] = op2;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int marks;
        cin >> marks;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        memset(dp, -1, sizeof(dp));

        if (subset(n, 1000 - marks, a))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}