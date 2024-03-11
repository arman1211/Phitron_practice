// #include <bits/stdc++.h>
// using namespace std;
// int dp[1005][1005];

// bool chocolate(int n, int s, int a[])
// {
//     if (n == 0)
//     {
//         if (s == 0)
//             return true;
//         else
//             return false;
//     }
//     if (dp[n][s] != -1)
//     {
//         return dp[n][s];
//     }

//     if (a[n - 1] <= s)
//     {
//         bool op1 = chocolate(n - 1, s - a[n - 1], a);
//         bool op2 = chocolate(n - 1, s, a);
//         return dp[n][s] = op1 || op2;
//     }
//     else
//     {
//         bool op2 = chocolate(n - 1, s, a);
//         return dp[n][s] = op2;
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int sum = 0;

//         int a[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//             sum += a[i];
//         }

//         for (int i = 0; i <= n; i++)
//         {
//             for (int j = 0; j <= sum / 2; j++)
//             {
//                 dp[i][j] = -1;
//             }
//         }

//         if (sum % 2 == 0)
//         {
//             if (chocolate(n, sum / 2, a))
//                 cout << "YES" << endl;
//             else
//                 cout << "NO" << endl;
//         }
//         else
//             cout << "NO" << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        bool dp[n + 1][sum / 2 + 1];
        dp[0][0] = true;
        for (int i = 1; i <= sum / 2; i++)
        {
            dp[0][i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum / 2; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (sum % 2 == 0)
        {
            if (dp[n][sum / 2])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}