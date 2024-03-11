#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> v;
        int n = 4;
        while (n--)
        {

            int x, y;
            cin >> x >> y;

            v.push_back({x, y});
        }

        int length;
        for (int i = 0; i < 4; i++)
        {
            if (v[i].first == v[i + 1].first)
            {
                length = sqrt(pow((v[i].second - v[i + 1].second), 2));
                break;
            }
            else if (v[i].first == v[i + 2].first)
            {
                length = sqrt(pow((v[i].second - v[i + 2].second), 2));
                break;
            }
        }
        cout << length * length << endl;
    }

    return 0;
}