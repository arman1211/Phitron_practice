#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a = 0;
        int b = 0;
        string s;
        cin >> s;
        for (int i = 0; i < 5; i++)
        {
            if (s[i] == 'A')
                a++;
            else
                b++;
        }
        if (a > b)
            cout << 'A' << endl;
        else
            cout << 'B' << endl;
    }

    return 0;
}