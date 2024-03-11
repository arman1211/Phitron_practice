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
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int biggest = INT_MIN;
        int biggestIndex;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > biggest)
            {
                biggest = a[i];
                biggestIndex = i;
            }
        }
        int sBig = INT_MIN;
        int sBigIndex;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > sBig && a[i] < biggest)
            {
                sBig = a[i];
                sBigIndex = i;
            }
        }
        if (biggestIndex < sBigIndex)
        {
            cout << biggestIndex << " " << sBigIndex << endl;
        }
        else
            cout << sBigIndex << " " << biggestIndex << endl;
    }
    return 0;
}