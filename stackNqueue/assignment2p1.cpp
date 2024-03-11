#include <bits/stdc++.h>
using namespace std;
 
int main() {
    stack<int> a;
    queue<int> b;
    int n,m;
    cin>>n>>m;
    while(n--){
        
        int val;
        cin>>val;
        a.push(val);
    }
    while(m--){
        
        int val;
        cin>>val;
        b.push(val);
    }
    bool flag = true;
    if(a.size()==b.size()){
        while(!a.empty() && !b.empty()){
        if(a.top()!=b.front()){
            flag= false;
            break;
        }
        else{
            a.pop();
            b.pop();
        }
         }
    }
    else flag = false;
    
    flag? cout<<"YES" : cout<<"NO";
    return 0;
}