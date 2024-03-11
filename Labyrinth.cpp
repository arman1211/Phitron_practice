#include <bits/stdc++.h>
using namespace std;
char mat[1005][1005];
vector<pair<int, int>> tr = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool vis[1005][1005];
int level[1005][1005];
int n, m;
bool flag = false;
int cnt = 0;
int ans = 0;
vector<char> ch;
vector<char> ch2;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    vis[si][sj] = true;
    level[si][sj] = 0;
    queue<pair<int, int>> q;
    q.push({si, sj});
    while (!q.empty())
    {
        pair<int, int> pr = q.front();
        int psi = pr.first;
        int psj = pr.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {

            int nsi = psi + tr[i].first;
            int nsj = psj + tr[i].second;
            if (valid(nsi, nsj) && !vis[nsi][nsj] && mat[nsi][nsj] != '#')
            {

                if (mat[nsi][nsj] == 'B')
                    flag = true;

                if (mat[nsi][nsj] == '.' || mat[nsi][nsj] == 'B')
                {

                    vis[nsi][nsj] = true;
                    q.push({nsi, nsj});
                    level[nsi][nsj] = level[psi][psj] + 1;
                    if (!flag)
                    {
                        if (i == 0)
                            ch.push_back('L');
                        if (i == 1)
                            ch.push_back('R');
                        if (i == 2)
                            ch.push_back('U');
                        if (i == 3)
                            ch.push_back('D');
                    }
                }
            }
        }
    }
}

int main()
{
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (mat[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    bfs(si, sj);
    cout << level[di][dj] << endl;
    if (flag)
    {
        cout << "YES" << endl;

        for (char c : ch)
        {
            cout << c;
        }
    }
    else
        cout << "NO" << endl;

    return 0;
}