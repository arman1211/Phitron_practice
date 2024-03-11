#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int grid[N][N];

int knapsack(int n, int weight[], int value[], int W)
{
    if (n <= 0 || W == 0)
        return 0;
    if (grid[n][W] != -1)
    {
        return grid[n][W];
    }
    if (weight[n] <= W)
    {
        int op1 = knapsack(n - 1, weight, value, W - weight[n]) + value[n];
        int op2 = knapsack(n - 1, weight, value, W);
        return grid[n][W] = max(op1, op2);
    }
    else
    {

        int op1 = knapsack(n - 1, weight, value, W);
        return grid[n][W] = op1;
    }
}

int main()
{
    int n;
    cin >> n;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int W;
    cin >> W;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            grid[i][j] = -1;
        }
    }
    cout << knapsack(n - 1, weight, value, W);
    return 0;
}