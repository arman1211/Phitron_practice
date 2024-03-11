#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool vis[100];
int par[100];
bool flag;
void dfs(int src){
    vis[src] = true;
    cout<<src<<" ";
    for(int child:adj[src]){
        if(vis[child] && par[src] != child) flag = true;
        if(!vis[child]){
            par[child]=src;
            dfs(child);
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
    memset(vis,false,sizeof(vis));
    memset(par,-1,sizeof(par));
    flag = false;
    dfs(0);
    if(flag) cout<<"found";
    else cout<<"Not found";  
    return 0;
}