#include <bits/stdc++.h>

using namespace std;
 
int main() {
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        bool flag=true;
        

        if(s.length()==14){
            if(s[0]!='+' || s[1] != '8' || s[2] != '8' || s[3]!= '0'){
                flag = false;
            }
            if(s[4] != '1' || (int(s[5])-48) < 2 ) {
                flag = false;
            }
            for(int i=5;i<14;i++){
            if(s[i] == '+') {
                flag= false;
                break;
            }
        }
        }
        
        else{
            flag = false;
        }
        
        flag? cout<<"YES"<<endl : cout<<"NO"<<endl;
        }
    
    return 0;
}