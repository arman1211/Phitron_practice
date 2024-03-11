#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node *next;
        Node *prev;
        Node(int val){
            this->val=val;
            this->next=NULL;
            this->prev= NULL;
        }
};

class myStack{
    public:
        int sz=0;
        Node * head = NULL;
        Node * tail = NULL;
    void push(int val){
        sz++;
        Node *newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev= tail;
        tail = tail->next;
    }
    void pop(){
        sz--;
        Node *deleteNode = tail;
        if(head == tail) {
            head = NULL;
            tail = NULL;
            return;
        }
        tail = tail->prev;
        delete deleteNode;
    }
    int top(){
        
        return tail->val;
    }
    int size(){
        return sz;
    }
    bool empty(){
        if(sz==0) return true;
        else return false;
    }    
};

class myQueue{
    public:
        Node * head = NULL;
        Node * tail = NULL;
        int sz=0;
    void push(int val){
        sz++;
        Node *newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev= tail;
        tail = tail->next;
    }
    void pop(){
        sz--;
        Node *deleteNode = head;
        
        head = head->next;
        
        delete deleteNode;
        if(head == NULL){
            tail == NULL;
        }
    }
    int front(){
        
        return head->val;
    }
    int size(){
        return sz;
    }
    bool empty(){
        if(sz==0) return true;
        else return false;
    }  
};
 
int main() {
    myStack a;
    myQueue b;
    int n,m;
    cin>>n>>m;
    while(n--){
        int val;
        cin>>val;
        a.push(val);
    }
    while(m--){
        int val;
        cin>>val;
        b.push(val);
    }
    bool flag = true;
    if(a.size()==b.size()){
        while(!a.empty() && !b.empty()){
        if(a.top()!=b.front()){
            flag= false;
            break;
        }
        else{
            a.pop();
            b.pop();
        }
         }
    }
    else flag = false;
    
    flag? cout<<"YES" : cout<<"NO";
      
    return 0;
}