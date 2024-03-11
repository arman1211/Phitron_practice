#include <bits/stdc++.h>
using namespace std;
class Student{
    public:
        string name;
        int roll;
        int mark;
        Student(string name,int roll,int mark){
            this->name= name;
            this->roll=roll;
            this->mark= mark;
        }
};
class cmp{
    public:
        bool operator()(Student a,Student b){
            if(a.mark==b.mark) return a.roll>b.roll;
            return a.mark<b.mark;
        }
};
 
int main() {
    priority_queue<Student,vector<Student>,cmp> pq;
    int n;
    cin>>n;
    while(n--){

        string name;
        int roll,mark;
        cin>>name>>roll>>mark;
        Student obj(name,roll,mark);
        pq.push(obj);

    }
    int q;
    cin>>q;
    while(q--){
        int cm;
        cin>>cm;
        if(cm==0){
           string name;
            int roll,mark;
            cin>>name>>roll>>mark;
            Student obj(name,roll,mark);
            pq.push(obj);
            if(!pq.empty()) cout<<pq.top().name<<" "<<pq.top().roll<<" "<<pq.top().mark<<endl;
            else cout<<"Empty"<<endl;
        }
        if(cm==1){
            if(!pq.empty()) cout<<pq.top().name<<" "<<pq.top().roll<<" "<<pq.top().mark<<endl;
            else cout<<"Empty"<<endl;
        }
        if(cm==2){
            if(!pq.empty()) pq.pop();
            if(!pq.empty()) cout<<pq.top().name<<" "<<pq.top().roll<<" "<<pq.top().mark<<endl;
            else cout<<"Empty"<<endl;
        }
    }  
    return 0;
}