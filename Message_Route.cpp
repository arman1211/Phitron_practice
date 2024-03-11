#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+ 5;
int par[N];
bool vis[N];
int level[N];
vector<int> v[N];

void bfs(int src){
    queue<int> q;
    level[src]=0;
    vis[src]=true;
    q.push(src);
    while(!q.empty()){
        int pr = q.front();
        q.pop();
        for(int ch: v[pr]){
            // cout<<ch<<" ";
            if(!vis[ch]){
                vis[ch]=true;
                // cout<<ch<<endl;
                level[ch]= level[pr]+1;
                par[ch]=pr;
                q.push(ch);
            }
        }
        
    }
}
 
int main() {
    int n,e;
    cin>>n>>e;
    memset(vis,false,sizeof(vis));
    memset(par,-1,sizeof(par));
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    int x=n;
    vector<int> ans;
    while (par[x]!=-1)
    {
        ans.push_back(x);
        x= par[x];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    if(par[n]==-1) cout<<"IMPOSSIBLE";
    else{
        cout<<ans.size()<<endl;
    for(int c:ans){
        cout<<c<<" ";
    }
    }
     
    return 0;
}