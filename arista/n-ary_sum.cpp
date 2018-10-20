#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  vector<Node*>child;
};
int max_s=0;
Node* resnode=NULL;
vector<int>res;
void max_sum(Node*root){
    if(root==NULL)
        return;
    int cur_sum=root->val;
    int count=root->child.size();
    for(int i=0;i<count;i++){
        cur_sum+=root->child[i]->val;
        max_sum(root->child[i]);
    }
    
    if(cur_sum>max_s){
        max_s=cur_sum;
        resnode=root;
    }
    return;
}
Node*newNode(int x){
    // Node* nn=(Node*)malloc(sizeof(Node*));
    Node*nn= new Node;
    nn->val=x;
    return nn;
}
int all_sum(Node*root){
    if(root==NULL)
    return 0;
    int sum=0;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*nn=q.front();
        q.pop();
        sum=sum+nn->val;
        
        for(int i=0;i<nn->child.size();i++){
            q.push(nn->child[i]);
        }
        
    }
    
    return sum;
}
void path_sum(Node*root,int cost){
    if(root->child.size()==0){
        //cout<<cost;
        res.push_back(cost+root->val);
        return;
    }
    int cur_sum=root->val;
    int count=root->child.size();
    for(int i=0;i<count;i++){
        path_sum(root->child[i],cost+cur_sum);
    }
    
    return;
}

int main() {
     Node* root = newNode(1); 
    (root->child).push_back(newNode(2)); 
    (root->child).push_back(newNode(3)); 
    (root->child).push_back(newNode(4)); 
    (root->child[0]->child).push_back(newNode(5)); 
    (root->child[0]->child).push_back(newNode(6)); 
    (root->child[2]->child).push_back(newNode(5)); 
    (root->child[2]->child).push_back(newNode(6)); 
    (root->child[2]->child).push_back(newNode(6)); 
    max_sum(root);
    cout<<resnode->val<<endl;
    cout<<max_s<<endl;
	cout<<all_sum(root)<<endl;
	return 0;
}
