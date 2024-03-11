#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int q;
    cin>>q;
    while(q--){
        stack<char> st;
        string s;
        cin>>s;
        
        for(int i=0;i<s.length();i++){
            if(st.empty()) st.push(s[i]);
            
            else if(s[i] =='1' && st.top()=='0'){
                st.pop();
                
            }
            else if(s[i] =='0' && st.top()=='1'){
                st.pop();
                
            }
            else st.push(s[i]);
        }
        if(st.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    
    }
      
    return 0;
}