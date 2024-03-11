#include <bits/stdc++.h>
using namespace std;

 
int main() {
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        map<string,int> mp;
        string s;
        getline(cin,s);
        stringstream ss(s);
        string word,ans;
        
        int mx = INT_MIN;
        while(ss>>word){
            
            mp[word]++;
            if(mp[word]>mx){
                mx = mp[word];
                ans = word;
            }
        }
        
        cout<<ans<<" "<<mx<<endl;  
    }
    return 0;
}