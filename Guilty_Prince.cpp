#include <bits/stdc++.h>
using namespace std;
char mat[21][21];
bool vis[21][21];
int n,m;
int ans;
vector<pair<int, int>> tr = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si,int sj){
    vis[si][sj]=true;
    for(int i=0;i<4;i++){
        int nsi = si + tr[i].first;
        int nsj = sj + tr[i].second;
        if(valid(nsi,nsj) && !vis[nsi][nsj] && mat[nsi][nsj]== '.'){
            ans++;
            // cout<<nsi<<" "<<nsj<<endl;
            dfs(nsi,nsj);
        }
    }
}
 
int main() {
    int ne;
    cin>>ne;
    for(int i=1;i<=ne;i++){
        memset(vis,false,sizeof(vis));
       
        ans=0;
        cin>>m>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='@'){
                    ans++;
                    dfs(i,j);

                }
            }
        }
        cout<<ans<<endl;
    }
      
    return 0;
}