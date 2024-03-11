#include <bits/stdc++.h>
using namespace std;
int dp[100005];

bool canMake(long long s, int n)
{
    if (s == n)
        return true;
    if (s > n)
        return false;
    if (dp[s] != -1)
        return dp[s];
    bool op1 = canMake(s + 3, n);
    bool op2 = canMake(s * 2, n);

    return dp[s] = op1 || op2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        if (canMake(1, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}