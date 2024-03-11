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
        char a[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        int i = 0;
        int cnt = 0;
        while (i < n - 1)
        {
            if (a[i + 1] == '@')
            {
                cnt++;
                i++;
                continue;
            }
            if (a[i + 2] == '@')
            {
                cnt++;
                i += 2;
                continue;
            }
            if (a[i + 1] == '.')
            {
                i++;
            }
            if (a[i + 1] == '*' && a[i + 2] != '*')
            {
                i++;
                continue;
            }
            if (a[i + 1] == '*' && a[i + 2] == '*')
            {
                break;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}