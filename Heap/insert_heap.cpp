#include <bits/stdc++.h>
using namespace std;

void insertHeapMax(vector<int> &v,int x){
    v.push_back(x);
    int curIdx = v.size()-1;
    
    while(curIdx!=0){
        int parIdx = (curIdx-1)/2;
        if(v[curIdx]>v[parIdx]){
            swap(v[curIdx],v[parIdx]);
            curIdx=parIdx;
        }
        else break;
    }

    
}
 
int main() {
    vector<int> v;
    int n;cin>>n;
    while(n--){
        int x;
        cin>>x;
        insertHeapMax(v,x);
    }
    for(int val:v) cout<<val<<" ";  
    return 0;
}