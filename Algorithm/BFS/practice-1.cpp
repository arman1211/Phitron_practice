#include <bits/stdc++.h>
using namespace std;
vector<int> mat[105];
bool vis[105];
int level[105];
int parent[105];
void bfs(int src){
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    queue<int> q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    while(!q.empty()){
        int par = q.front();
        q.pop();
        // cout<<par<<" ";
        for(int child:mat[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                level[child] = level[par]+1;
                parent[child] = par;
            }
        }
    }
}

int main() {
    
    int v,e;
    cin>>v>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int q;
    cin>>q;
    while(q--){
        int src,des;
        cin>>src>>des;
        vector<int> path;
        bfs(src);
        int x=des;
        while(x!=-1){
            
            path.push_back(x);
            x=parent[x];
        }
        for(int val:path) cout<<val<<" ";
        // cout<<path.size()<<endl; 
    } 
    return 0;
}