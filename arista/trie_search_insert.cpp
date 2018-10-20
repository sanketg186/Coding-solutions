#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
  TrieNode* child[256];
  bool end_word;
};
TrieNode*getNode(){
    
    TrieNode* nn=new TrieNode;
    nn->end_word=false;
    
    for(int i=0;i<256;i++){
        nn->child[i]=NULL;
    }
    
    return nn;
}

void insert(TrieNode*root,string key){
    int i;
    TrieNode* temp=root;
    for(i=0;i<key.size();i++){
        int in=key[i]-'a';
        if(!temp->child[in]){
            temp->child[in]=getNode();
        }
        temp=temp->child[in];
    }
    temp->end_word=true;
}
bool search(TrieNode*root,string key){
    int i;
    TrieNode*temp=root;
    for(i=0;i<key.size();i++){
        int in=key[i]-'a';
        if(!temp->child[in])
            return false;
        temp=temp->child[in];
        
    }
    return (temp!=NULL&&temp->end_word);
   
}
int main()
 {
     int t;
     cin>>t;
     while(t--){
         int n;
         string s;
         vector<string>vec;
         cin>>n;
         TrieNode *root = getNode(); 
         for(int i=0;i<n;i++){
             cin>>s;
             insert(root,s);
         }
         cin>>s;
         cout<<search(root,s)<<endl;
     }
	//code
	return 0;
}
