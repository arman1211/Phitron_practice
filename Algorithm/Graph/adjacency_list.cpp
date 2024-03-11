#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,e;
    cin>>n>>e;
    vector<int> mat[n];
    while(e--){
        int a,b;
        cin>>a>>b;
        mat[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        for(int v:mat[i]){
            cout<<v<<" ";
        }
        cout<<endl;
    }
      
    return 0;
}