#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> adj[N];
bool vis[N];
int dis[N];
int ans;

void bfs(int s){
    queue<int> q ;
    q.push(s);
    vis[s]=true;
    dis[s]=0;
    while(!q.empty()){
        int par = q.front();
        q.pop();
        for(int ch:adj[par]){
            
            if(!vis[ch]){
             ans++;
                
                vis[ch]=true;
                q.push(ch);
                dis[ch]= dis[par]+1;

            }
        }
    }
}
 
int main() {
    int t;
    int cs=1;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        while(e--){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        } 
        memset(vis,false,sizeof(vis));
        memset(dis,-1,sizeof(dis));
        int s,d;
        cin>>s>>d;
        int ans= INT_MIN;
        for(int i=0;i<n;i++){
            bfs(s);
            int disfromsourse = dis[i];
            memset(vis,false,sizeof(vis));
            memset(dis,-1,sizeof(dis));
            bfs(d);
            int disfromdest = dis[i];
            // cout<<disfromsourse<<" "<<disfromdest<<endl;
            memset(vis,false,sizeof(vis));
            memset(dis,-1,sizeof(dis));
            ans=max(ans,(disfromdest+disfromsourse));
        } 
        cout<<"Case "<<cs++<<": "<<ans<<endl;
        for(int i=0;i<n;i++) adj[i].clear();
    }
    return 0;
}