#include<bits/stdc++.h>


using namespace std;
char mat[100][100];
vector<pair<int, int> > tr ;
bool vis[100][100];
int level[100][100];
int n;



bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    vis[si][sj] = true;
    level[si][sj] = 0;
    queue<pair<int, int> > q;
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
            if (valid(nsi, nsj) && !vis[nsi][nsj] && mat[nsi][nsj] != 'T')
            {

                

                    vis[nsi][nsj] = true;
                    q.push({nsi, nsj});
                    level[nsi][nsj] = level[psi][psj] + 1;
                    
                
            }
        }
    }
}

int main()
{
    tr.push_back({0, -1});
    tr.push_back({0, 1});
    tr.push_back({-1, 0});
    tr.push_back({1, 0});
    while(cin>>n){
        int si, sj, di, dj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (mat[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));

        bfs(si, sj);
        cout << level[di][dj] << endl;

    }
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         vis[i][j]=false;
    //         level[i][j]=-1;
    //     }
    // }
    
   

    return 0;
}