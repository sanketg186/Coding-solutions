//kosaraju strongly connected componenet
//Dilku was thinking about the first time he met his girl... It was indeed a walk to remember. The romantic weather and her silly talks. He was completely mesmarized. Those were the days!..

//Today is his girl's birthday and he wants to make it special for her. He wants to again take her on a "special walk" that they would remember for the lifetime.

//The city in which Dilku lives is represented as an unweighted directed graph with N nodes and M edges. A "special walk" in the graph starting at node u is a simple path that begins and ends at the same node u.

//Formally, A special walk is path u , a1 , a2 , a3 ,..., ai ,.... , u where ai are distinct and not equal to u for all i.

//Now since Dilku is really nervous about taking his girl out, he needs your help. For every node in the given graph, tell whether it is possible for Dilku to take his girl on a "special walk" starting at that node.
// Write your code here
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void dfs(int v,vector<int>adj[],vector<bool>&visit,stack<int>&stk){
    visit[v]=true;
    
    for(int i=0;i<adj[v].size();i++){
        
        if(visit[adj[v][i]]==false){
            dfs(adj[v][i],adj,visit,stk);
        }
        
    }
    
    stk.push(v);
    
}

void dfs2(int v,vector<int>adj[],vector<bool>&visit,vector<int>&temp){
    visit[v]=true;
    //cout<<v<<" ";
    temp.push_back(v);
    for(int i=0;i<adj[v].size();i++){
        
        if(visit[adj[v][i]]==false){
            dfs2(adj[v][i],adj,visit,temp);
        }
        
    }
}

int main(){
    int i,j,x,y,n,m;
    vector<vector<int>>res;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>reverse[n+1];
    vector<bool>visit(n+1,false);
    stack<int>stk;
    for(i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        reverse[y].push_back(x);
    }
    
    for(i=1;i<=n;i++){
        if(visit[i]==false){
            dfs(i,adj,visit,stk);
        }
        
    }
    vector<bool>visit2(n+1,false);
    
    while(!stk.empty()){
        int v=stk.top();
        stk.pop();
        if(visit2[v]==false){
            vector<int>temp;
            dfs2(v,reverse,visit2,temp);
            res.push_back(temp);
            
        }
    }
    
    vector<int>r(n+1,0);
    for(i=0;i<res.size();i++){
        if(res[i].size()>1){
            for(j=0;j<res[i].size();j++){
                r[res[i][j]]=1;
            }
        }
    }
    
    for(i=1;i<r.size();i++){
        cout<<r[i]<<" ";
    }
    cout<<endl;
    return 0;
}
