#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
const ll N =1e5+5;
ll dis[N];
vector<pair<ll,ll>> v[N];
ll par[N];

class cmp
{
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(ll src){
     priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    pq.push({src,0});
    dis[src]=0;
    while(!pq.empty()){
        pair<ll,ll> pr = pq.top();
        pq.pop();
        ll parNode = pr.first;
        ll parCost = pr.second;
        for(pair<ll,ll> ch:v[parNode]){
            ll childNode = ch.first;
            ll childCost = ch.second;
            if(dis[parNode]+ childCost < dis[childNode])
            {
                dis[childNode]= dis[parNode]+childCost;
                pq.push({childNode,dis[childNode]});
                par[childNode]=parNode;
            }
        }
    }
}
 
int main() {
    ll n,e;
    cin>>n>>e;
    while(e--){
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    } 
    for(ll i=1;i<=n;i++){
        dis[i] = 1e18;
        par[i]=-1;
    } 
    dijkstra(1);
    // for(ll i=1;i<=n;i++){
    //     cout<<dis[i]<<" " ;
    // }
    ll x=n;
    vector<ll> ans;
    while(x!=-1){
      
        ans.push_back(x);
        x=par[x];
    } 
    reverse(ans.begin(),ans.end());
    if(ans.size()>1){
        for(ll xn:ans){
        cout<<xn<<" ";
    }
    }
    else cout<<-1;
    return 0;
}