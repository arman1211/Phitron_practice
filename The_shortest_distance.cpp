#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int mat[N][N];
vector<int> v[N];
bool vis[N];
int dis[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    dis[src]=0;
    while (!q.empty())
    {
        int par=q.front();
        q.pop();
        for(int x:v[par]){
            if(!vis[x]){
                vis[x]=true;
                dis[x]=dis[par]+1;
                q.push(x);
            }
        }
    }
    
}

 
int main() {
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mat[i][j]==1){
                v[i].push_back(j);
            }
        }
    }
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));

    bfs(x);
    
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
      
    return 0;
}