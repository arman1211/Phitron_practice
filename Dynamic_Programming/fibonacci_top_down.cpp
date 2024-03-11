#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5;
long long a[N];

long long fib(long long n){
    if(n==0 || n==1) return n;
    if(a[n]!=-1) return a[n];

    long long ans = fib(n-1) + fib(n-2);
    a[n]=ans;
    return ans;
}
 
int main() {
    long long n;
    cin>>n;
    memset(a,-1,sizeof(a));
    cout<<fib(n)<<endl;  
    return 0;
}