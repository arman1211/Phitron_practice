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
        int cnt1 = 0;
        int cnt2 = 0;
        char a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == ')')
                cnt1++;
            else if (a[i] == '(')
                cnt2++;
        }
        if (n % 2 == 0)
        {

            if (cnt1 == cnt2)
                cout << "Possible" << endl;
            else
                cout << "Impossible" << endl;
        }
        else
            cout << "Impossible" << endl;
    }

    return 0;
}