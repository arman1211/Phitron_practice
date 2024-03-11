#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int arr1[26] = {0};
        int arr2[26] = {0};
        for(char c:s1){
            arr1[int(c)-97]++;
        }  
        for(char c:s2){
            arr2[int(c)-97]++;
        }
        bool flag = true;
        for(int i=0;i<26;i++){
            if(arr1[i]!= arr2[i]){
                flag = false;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl; 
    } 
    return 0;
}