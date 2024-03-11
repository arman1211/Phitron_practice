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
    if(val ==-1) root = NULL;
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty()){
        Node* f = q.front();
        q.pop();

        int l,r;
        cin>>l>>r;
        Node* myLeft;
        Node* myRight;
        if(l==-1) myLeft = NULL;
        else myLeft = new Node(l);
        if(r==-1) myRight = NULL;
        else myRight= new Node(r);

        f->left=myLeft;
        f->right=myRight;

        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
    return root;
}
void level_order(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* f = q.front();
        q.pop();
        cout<<f->val<<" ";
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}

bool searchInBST(Node* root,int x){
    if(root == NULL) return false;
    if(x==root->val) return true;
    
    if(x<root->val){
        return searchInBST(root->left,x);

    }
    if(x>root->val){
        return searchInBST(root->right,x);
    }
}


void inputBST(Node* &root,int x){
    
    if(root==NULL) root = new Node(x);
    if(x<root->val){
        if(root->left) inputBST(root->left,x);
        else root->left= new Node(x);
    }
    if(x>root->val){
        if(root->right) inputBST(root->right,x);
        else root->right= new Node(x);
    }
    
}

Node* converArr2BST(int a[],int n,int l,int r){
    if(l>r) return NULL;
    int mid = (l+r)/2;
    Node* root = new Node(a[mid]);
    Node* leftRoot = converArr2BST(a,n,l,mid-1);
    Node* rightRoot = converArr2BST(a,n,mid+1,r);
    root->left= leftRoot;
    root->right = rightRoot;
    return root;

}
 
int main() {
    // Node* root = NULL;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    Node* root = converArr2BST(a,n,0,n-1);


    // while(true){
    //     int x;cin>>x;
    //     if(x==-1) break;
    //     inputBST(root,x);
    // }
    level_order(root);
    // int x;cin>>x;
    // if(searchInBST(root,x)) cout<<"YES,found";
    // else cout<<"Not found";  
    return 0;
}