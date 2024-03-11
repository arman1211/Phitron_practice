#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int ans = 0;
    if (n < 10)
    {
        for (int i = 1; i <= n; i++)
        {
            ans += i;
        }
    }
    if (n >= 10)
    {
        while (n >= 0)
        {
            ans += 45;
            n = n - 9;
            if (n < 9)
            {
                for (int i = 1; i <= n; i++)
                {
                    ans += i;
                }
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}