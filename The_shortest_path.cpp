#include <bits/stdc++.h>
using namespace std;
const int N =5e4 +5;
vector<int> adj[N];
int vis[N];
int par[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    while (!q.empty())
    {
        int pr = q.front();
        q.pop();
        for(int x:adj[pr]){
            if(!vis[x]){
                par[x]=pr;
                vis[x]=true;
                q.push(x);
            }
        }
    }
    
}
 
int main() {
    int n,e;
    cin>>n>>e;
    int s,d;
    cin>>s>>d;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }  
    memset(vis,false,sizeof(vis));
    memset(par,-1,sizeof(par));
    bfs(s);
    int x=d;
    
    stack<int> st;
    while (x!=-1)
    {
        st.push(x);
        x=par[x];
    }
    if(par[d]==-1){
        cout<<-1;
    }
    else{
        cout<<st.size()-1<<endl;
        while (!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
    
    
    return 0;
}