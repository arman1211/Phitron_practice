#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int Gsize[N];
int level[N];

void dsu_initialize(){
    for(int i=0;i<100;i++){
        parent[i]=-1;
        Gsize[i]=1;
        level[i]=0;
    }
    
}

int dsu_find(int node){
    if(parent[node]==-1) return node;
    int leader=  dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union(int node1,int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    parent[leaderA] = leaderB;
}
void dsu_union_by_size(int node1,int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
   
    if(Gsize[leaderA]>Gsize[leaderB]){
        parent[leaderB]=leaderA;
        Gsize[leaderA]+= Gsize[leaderB];

    }
    
    else {
        parent[leaderA]=leaderB;
        Gsize[leaderB]+=Gsize[leaderA];
    }

}

void dsu_union_by_rank(int node1,int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(level[leaderA] > level[leaderB]){
        parent[leaderB] = leaderA;
    }
    if(level[leaderB] > level[leaderA]){
        parent[leaderA] = leaderB;
    }
    else {
        parent[leaderA] = leaderB;
        level[leaderB]++;
    }
}
 
int main() {
    dsu_initialize();  
    
    
    dsu_union_by_size(1,2);
    dsu_union_by_size(1,3);
    dsu_union_by_size(3,4);
    dsu_union_by_size(6,7);
    dsu_union_by_size(3,7);

    cout<<dsu_find(7)<<endl;
    cout<<dsu_find(2)<<endl;

    cout<<Gsize[dsu_find(2)]<<endl;
    cout<<Gsize[dsu_find(7)]<<endl;
    
    // for(int i=0;i<8;i++){
    //     cout<<parent[i]<<endl;
    // }
    return 0;
}