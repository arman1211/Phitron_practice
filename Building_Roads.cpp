#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int par[N];
int group_size[N];
bool vis[N];
vector<int> v[N];

void dsu_init(int n){
    for(int i=1;i<=n;i++){
        par[i]=-1;
        group_size[i]=0;
        vis[i]=false;
    }
}

void dfs(int src){
    vis[src]=true;
    for(int x:v[src]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int dsu_find(int node){
    if(par[node]==-1) return node;
    int leader = dsu_find(par[node]);
    par[node] = leader ;
    return leader;
}

void dsu_union(int node1,int node2){
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if(group_size[leader1]> group_size[leader2]){
        par[leader2]=leader1;
        group_size[leader1]+= group_size[leader2];
    }
    else{
        par[leader1]=leader2;
        group_size[leader2]+= group_size[leader1];
    }
}
 
int main() {
    int n,e;
    cin>>n>>e;
    int cnt=0;
    dsu_init(n);
    vector<int> leader;
    while(e--){
        int a,b;
        cin>>a>>b;
        int leader1 = dsu_find(a);
        int leader2 = dsu_find(b);
       if(leader1!= leader2)dsu_union(a,b);
        

    } 
    for(int i = 1;i<=n;i++){
        leader.push_back(dsu_find(i));
    } 
    unordered_set<int> s(leader.begin(),leader.end());
    leader.assign(s.begin(),s.end());
    cout<<leader.size()-1<<endl;
    for(int i=0;i<leader.size()-1;i++){
        cout<<leader[i]<<" "<<leader[i+1]<<" ";
    }
    // cout<<cnt;
    return 0;
}