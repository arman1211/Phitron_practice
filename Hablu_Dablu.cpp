#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    cin >> n >> h;
    int a[n];
    int best = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > best)
        {
            best = a[i];
        }
    }
    best--;
    int habhealth = h;
    while (habhealth >= 1)
    {
        if (best > 0)
        {
            habhealth -= best;

            best--;
        }
        else
        {

            break;
        }
    }
    if (habhealth < 1)
        cout << "Dablu" << endl;
    else
        cout << "Hablu" << endl;
    return 0;
}