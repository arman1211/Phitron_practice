#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node* left;
        Node* right;
    Node(int val){
        this->val= val;
        this->left= NULL;
        this->right= NULL;
    }
};
Node* input_binary(){
    int val;
    cin>>val;
    Node* root = new Node(val);
    if(val==-1) root=NULL;

    queue<Node*> q;
    if(root) q.push(root);


    while(!q.empty()){
        Node* f = q.front();
        q.pop();

        int l,r;
        cin>>l>>r;
        Node* lf;
        Node* rt;
        if(l!=-1) lf= new Node(l);
        else lf=NULL;
        
        if(r!=-1) rt= new Node(r);
        else rt=NULL;

        f->left= lf;
        f->right= rt;


        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);

        
    }
    return root;

}

void level_order(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* f = q.front();
        q.pop();
        cout<<f->val<<" ";
        if(f->right) q.push(f->right);
        if(f->left) q.push(f->left);
    }
}
 
int main() {
    Node* root = input_binary();
    level_order(root) ; 
    return 0;
}