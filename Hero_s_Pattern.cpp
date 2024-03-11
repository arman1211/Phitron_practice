#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sp1 = n - 1;
    int sp2 = 0;
    int st1 = n;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= sp1; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= st1; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= sp2; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= st1; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= sp1; j++)
        {
            cout << " ";
        }
        if (i < n)
        {
            sp1--;
            st1--;
            sp2 += 4;
        }
        else
        {
            sp1++;
            st1++;
            sp2 -= 4;
        }
        cout << endl;
    }

    return 0;
}