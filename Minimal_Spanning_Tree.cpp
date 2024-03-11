#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];
class Edge{
    public:
        int u,v,w;
        Edge(int u,int v,int w){
            this->u=u;
            this->v=v;
            this->w=w;
        }
};
bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

void dsu_init(int n){
    for(int i=1;i<=n;i++){
        par[i]=-1;
        group_size[i]=1;
    }
}

int dsu_find(int node){
    if(par[node]==-1) return node;
    int leader = dsu_find(par[node]);
    par[node]= leader;
    return leader;
}
void dsu_union_size(int node1,int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(group_size[leaderA]> group_size[leaderB]){
        par[leaderB]=leaderA;
        group_size[leaderA]+=group_size[leaderB];
    }
    else{
        par[leaderA]=leaderB;
        group_size[leaderB]+=group_size[leaderA];
    }
}
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<Edge> edgelist;
    dsu_init(n);
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        edgelist.push_back(Edge(u,v,w));
    }
    sort(edgelist.begin(),edgelist.end(),cmp);
    int cost=0;
    for(Edge ed:edgelist){
        
        int leaderA = dsu_find(ed.u);
        int leaderB = dsu_find(ed.v);
        if(leaderA != leaderB){
            dsu_union_size(leaderA,leaderB);
            cost+=ed.w;
        }
        
    }
    cout<<cost;
    return 0;
}