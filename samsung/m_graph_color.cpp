//Given an undirected graph and m colors.wrtie program to check if it is m-colorable and also print the colors.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>res;
bool is_safe(vector<vector<int>>v,int c,int s,int n,vector<int>color){
    int i;
    for(i=0;i<n;i++){
        if(v[s][i]&&color[i]==c)
            return false;
    }
    return true;
}

int dfs(vector<vector<int>>v,int s,int k,vector<int>color,int n){
    int i;
    if(s==n)
        return 1;
    for(i=1;i<=k;i++){
        if(color[s]==0 &&is_safe(v,i,s,n,color)){
            color[s]=i;
            res.push_back(i);
            if(dfs(v,s+1,k,color,n)==1)
                return 1;
            
            color[s]=0;
            res.pop_back();
        }
    }
    
    return 0;
}

int main() {
	int i,n,m,k,x,y;
	cin>>n>>m>>k;
	vector<vector<int>>v(n,vector<int>(n,0));
	vector<int>color(n,0);
	for(i=0;i<m;i++){
	    cin>>x>>y;
	    v[x][y] = 1;
	    v[y][x] = 1;
	}
	
	int flag=dfs(v,0,k,color,n);
	if(flag==1){
    	cout<<"yes";
    	for(i=0;i<res.size();i++)
    	cout<<res[i]<<" ";
	}
	else
	    cout<<"no";
	return 0;
}
