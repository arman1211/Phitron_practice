#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

int knapsack(int n, int w, int weight[], int value[])
{

    if (n < 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (weight[n] <= w)
    {
        int op1 = knapsack(n - 1, w - weight[n], weight, value) + value[n];
        int op2 = knapsack(n - 1, w, weight, value);
        return dp[n][w] = max(op1, op2);
    }
    else
    {
        int op1 = knapsack(n - 1, w, weight, value);
        return dp[n][w] = op1;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int value[n], weight[n];
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << knapsack(n - 1, w, weight, value) << endl;
        }
    return 0;
}