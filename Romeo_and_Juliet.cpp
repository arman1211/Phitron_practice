#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +5;
vector<int> adj[N];
bool vis[N];
int level[N];


void bfs(int x,int y){
    queue<int> q;
    q.push(x);
    vis[x]=true;
    level[x]=0;
    while(!q.empty()){
        int pr = q.front();
        q.pop();
        for(int ch:adj[pr]){
            if(!vis[ch]){
                vis[ch]=true;
            level[ch]= level[pr]+1;
            q.push(ch);
            }
        }
    }
}
 
int main() {
    int n,e;
    cin>>n>>e;
    
    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int x,y,k;
    cin>>x>>y>>k;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    bfs(x,y);  
    if(level[y]!=-1){
        if(k*2 >= level[y]) cout<<"YES";
        else cout<<"NO";

    }
    else cout<<"NO";
    // cout<<level[y]<<endl;
    return 0;
}