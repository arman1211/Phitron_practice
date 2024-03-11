#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (ans < a[i])
                ans = a[i];
        }
        for (int j = i + 1; j < n; j++)
        {
            if ((a[i] + a[j]) % 2 == 0)
            {
                ans = max(ans, (a[i] + a[j]));
            }
        }
    }
    cout << ans;
    return 0;
}