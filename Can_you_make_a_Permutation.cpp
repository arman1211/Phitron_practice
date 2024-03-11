#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int tmp = k;

        for (int i = 0; i < n; i++)
        {

            if (v[i] > n)
            {
                k--;
            }
            if (v[i] == v[i + 1])
            {
                k--;
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != i + 1)
                flag = false;
        }
        if (k >= 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}