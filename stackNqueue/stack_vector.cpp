#include <bits/stdc++.h>
using namespace std;

class myStack{
    public:
        vector<int> v;
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        v.pop_back();
    }
    void top(){
        cout<<v.back();
    }
    int size(){
        return v.size();
    }
    bool empty(){
        if(v.empty() ) return true ;
        else return false;
    }
};
 
int main() {
    myStack st;
    st.push(10);
    st.top() ; 
    return 0;
}