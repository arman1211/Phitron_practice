#include <bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int> mat[105];
int level[105];

void bfs(int src){
    queue<int> q;
    vis[src] = true;
    level[src]=0;
    q.push(src);
    while(!q.empty()){
        int par = q.front();
        q.pop();
        cout<<par<<" ";
        for(int child:mat[par]){
            if(!vis[child]){
            q.push(child);
            vis[child]=true;
            level[child]=level[par]+1;
            // cout<<child<<" ";
        }
        }
    }


};
 
int main() {
    
    int n,e;
    cin>>n>>e;
    
    while(e--){
        int a,b;
        cin>>a>>b;
        mat[a].push_back(b);
        mat[b].push_back(a);

    }
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    int src;
    cin>>src;
    bfs(src);
    cout<<endl;
    for(int i=0;i<n;i++){
        if(level[i]!=-1){
            cout<<i<<" => "<<level[i]<<endl;
        }
    }
    // for(auto v:mat){
    //     cout<<v.size()<<" => ";
    //     for(int i=0;i<v.size();i++){
    //         cout<<v[i]<<" ";
    //     }
    //     cout<<endl;
    // }  
    return 0;
}