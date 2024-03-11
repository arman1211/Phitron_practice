#include <bits/stdc++.h>
using namespace std;
class cmp{
    public:
        bool operator()(int a,int b){
            return a>b;
        }
};
 
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    priority_queue<int,vector<int>,cmp> pq;
    for(int val:a) pq.push(val);
    int q;
    cin>>q;
    while(q--){
        int cmnd;
        cin>>cmnd;
        
            if(cmnd==0){
            int x;
            cin>>x;
            pq.push(x);
            if(!pq.empty()) cout<<pq.top()<<endl;
                else cout<<"Empty"<<endl;

            }
            if(cmnd == 1){
                if(!pq.empty()) cout<<pq.top()<<endl;
                else cout<<"Empty"<<endl;
            }
            if(cmnd == 2){
                if(!pq.empty()) pq.pop();
                if(!pq.empty()) cout<<pq.top()<<endl;
                else cout<<"Empty"<<endl;
                
            }
        
    }  
    return 0;
}