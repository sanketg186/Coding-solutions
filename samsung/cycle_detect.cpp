//Program to detect cycle in directed graph and print cycle

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int cycle_detect=0,sv=-1;
vector<int>cycle3;
void dfs(vector<vector<int>>v,int s,vector<bool>visit,vector<int>cycle,vector<int>cycle2){
    if(cycle_detect==1)
    return;
    visit[s]=true;
    cycle[s]=1;
    cycle2.push_back(s);
    int i,j;
    for(i=0;i<v[s].size();i++){
        if(v[s][i]&&visit[i]==false){
            dfs(v,i,visit,cycle,cycle2);
        }
        else if(v[s][i]&&visit[i]==true&&cycle[i]==1){
            sv=i;
            cycle_detect=1;
            vector<int>res;
	       // cout<<cycle2.size();
	        for(j=0;j<cycle2.size();j++){
	           // cout<<cycle2[j];
	            if(cycle2[j]==sv)
	                break;
	        }
	        for(;j<cycle2.size();j++){
	            res.push_back(cycle2[j]);
	        }
	        sort(res.begin(),res.end());
	        for(j=0;j<res.size();j++)
	            cout<<res[j]<<" ";
            return;
        }
    }
    cycle[s]=0;
    cycle2.pop_back();
}

int main() {
	int i,n,m,k,x,y,j;
	cin>>n>>m;
	vector<vector<int>>v(n,vector<int>(n,0));
	
	vector<bool>visit(n,0);
	for(i=0;i<m;i++){
	    cin>>x>>y;
	    v[x][y] = 1;
	}
	for(i=0;i<n;i++){
	    vector<int>cycle(n,0),cycle2;
	    if(visit[i]==false)
	        dfs(v,i,visit,cycle,cycle2);
	    if(cycle_detect==1){
	        cout<<1<<" ";
	        
	        break;
	    }
	}
	
	
	return 0;
}
