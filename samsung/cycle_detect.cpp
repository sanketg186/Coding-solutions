//Program to detect cycle in directed graph

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int cycle_detect=0;
void dfs(vector<vector<int>>v,int s,vector<bool>visit,vector<int>cycle){
    if(cycle_detect==1)
    return;
    visit[s]=true;
    cycle[s]=1;
    int i;
    for(i=0;i<v[s].size();i++){
        if(v[s][i]&&visit[i]==false){
            dfs(v,i,visit,cycle);
        }
        else if(v[s][i]&&visit[i]==true&&cycle[i]==1){
            cycle_detect=1;
            return;
        }
    }
    cycle[s]=0;
}

int main() {
	int i,n,m,k,x,y;
	cin>>n>>m;
	vector<vector<int>>v(n,vector<int>(n,0));
	
	vector<bool>visit(n,0);
	for(i=0;i<m;i++){
	    cin>>x>>y;
	    v[x][y] = 1;
	}
	for(i=0;i<n;i++){
	    vector<int>cycle(n,0);
	    if(visit[i]==false)
	        dfs(v,i,visit,cycle);
	    if(cycle_detect==1){
	        cout<<1<<" ";
	        break;
	    }
	}
	
	
	return 0;
}
