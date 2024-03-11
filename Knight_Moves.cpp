#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int row, col;
char grid[N][N];
bool visited[N][N];
int dis[N][N];

vector<pair<int, int>> t = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
;

bool valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
    {
        return false;
    }

    return true;
}

void bfs(int source_i, int source_j)
{
    queue<pair<int, int>> q;
    q.push({source_i, source_j});
    visited[source_i][source_j] = true;
    dis[source_i][source_j] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int child_i = parent.first + t[i].first;
            int child_j = parent.second + t[i].second;

            if (valid(child_i, child_j) && !visited[child_i][child_j])
            {
                visited[child_i][child_j] = true;
                dis[child_i][child_j] = dis[parent.first][parent.second] + 1;
                q.push({child_i, child_j});
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int s_i, s_j;
        int d_i, d_j;

        cin >> row >> col;
        cin >> s_i >> s_j;
        cin >> d_i >> d_j;

        memset(visited, false, sizeof(visited));
        memset(dis, -1, sizeof(dis));

        bfs(s_i, s_j);

        cout << dis[d_i][d_j] << endl;
    }
    return 0;
}
