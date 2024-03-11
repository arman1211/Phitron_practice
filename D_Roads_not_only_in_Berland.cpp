#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];

void dsu_initialize(int n){
    for(int i=1;i<=n;i++){
        par[i]=-1;
        group_size[i]=1;
    }
}
int dsu_find(int node){
    if(par[node]==-1) return node;
    int leader = dsu_find(par[node]);
    par[node]=leader;
    return leader;
}


void dsu_union(int node1,int node2){
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if(group_size[leader1]> group_size[leader2]){
        par[leader2]=leader1;
        group_size[leader1]+=group_size[leader2];
    }
    else {
         par[leader1]=leader2;
        group_size[leader2]+=group_size[leader1];
    }
}
 
int main() {
    vector<pair<int,int>> todelete;
    vector<pair<int,int>> tocreate;
    int n;
    cin>>n;
    dsu_initialize(n);
    int e=n-1;
    int init;
    bool flag=false;
    while(e--){
        int a,b;
        cin>>a>>b;
        if(!flag){
            init = a;
            flag=true;
        }
        int leader1= dsu_find(a);
        int leader2 = dsu_find(b);
        
        if(leader1!=leader2){
            dsu_union(a,b);
            
        }
        else {
            todelete.push_back({a,b});

        }
    }
   
    
    for(int i=2;i<=n;i++){
        int leaderInit = dsu_find(1);
        int leaderB = dsu_find(i);
        if(leaderB != leaderInit){
            
            tocreate.push_back({1,i});
            dsu_union(1,i);
           
            
        } 
    }
    cout<<todelete.size()<<endl;
    for(int i=0;i<todelete.size();i++){
        cout<<todelete[i].first<<" "<<todelete[i].second<<" "<<tocreate[i].first<<" "<<tocreate[i].second<<endl;
    }  
    return 0;
}