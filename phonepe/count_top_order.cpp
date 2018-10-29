#include <iostream>
#include<bits/stdc++.h>
#define mod 1000000007 
using namespace std;

int fact(int n){
    if(n==1||n==0)
    return 1;
    return (fact(n-1)*n)%mod;
}
int dfs(vector<int>adj[],vector<bool>&visit,int v,int p){
    visit[v]=true;
    int i;
    int co=0;
    for(i=0;i<adj[v].size();i++){
        
        if(visit[adj[v][i]]==false){
            co++;
            p=(p*dfs(adj,visit,adj[v][i],p))%mod;
            
        }
        
    }
    
    return (fact(co)*p)%mod;
    
}

int main() {
	
	int n;
	
	vector<int>adj[6];
	vector<bool>visit(6,false);
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(4);
	adj[2].push_back(4);
	adj[2].push_back(5);
	
	int res=dfs(adj,visit,0,1);
	cout<<res<<endl;
	return 0;
}
