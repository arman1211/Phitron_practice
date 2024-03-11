#include <bits/stdc++.h>
using namespace std;
 
int main() {
    queue<string> q;
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>> t;
        if(t==0){
            string s;
            cin>>s;
            q.push(s);
        }
        if(t==1){
            if(!q.empty()){
                cout<<q.front()<<endl;
                q.pop();
            }
            else cout<<"Invalid"<<endl;
        }
    }  
    return 0;
}