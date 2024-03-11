#include <bits/stdc++.h>
using namespace std;
const int N =10000;
int s,f;
int mat[N][N];
vector<pair<int,int>> adj[N];
int dis[N];
class cmp{
    public:
        bool operator()(pair<int,int> a,pair<int,int> b){
                return a.second > b.second;
        }
};
void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({s,0});
    dis[s]=0;
    while(!pq.empty()){
        pair<int,int> par = pq.top();
        pq.pop();
        int parNode = par.first;
        int parCost = par.second;
        for(pair<int,int> pr:adj[parNode]){
            int childNode = pr.first;
            int childCost = pr.second;
            if(parCost+childCost < dis[childNode]){
                dis[childNode] = parCost + childCost;
                pq.push({childNode,dis[childNode]});
            }
        }
    }
    
}
 
int main() {
    int n;
    cin>>n>>s>>f;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }  
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=-1){
                adj[i].push_back({j,mat[i][j]});
            }
        }
    }
    for(int i=0;i<N;i++){
        dis[i]=INT_MAX;
    }
    dijkstra(s-1);
    if(dis[f-1] > N) cout<<-1<<endl;
    else cout<<dis[f-1]<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<adj[i].size();j++){
    //         cout<<i<<"----"<<adj[i][j].first<<"->>"<<adj[i][j].second<<endl;
    //     }
    // }  
    return 0;
}