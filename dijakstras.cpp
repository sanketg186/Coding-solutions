#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int i,j,n,m,x,y,w;
        cin>>n>>m;
        vector<pair<int,int>>a[n];
        for(i=0;i<m;i++){
            cin>>x>>y>>w;
            a[x].push_back(make_pair(y,w));
            a[y].push_back(make_pair(x,w));
        }
        
        pair<int,int> p;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        int src=0;
        pq.push(make_pair(0,src));
        dist[src]=0;
        
        while(!pq.empty()){
            int v=pq.top().second;
            pq.pop();
            
            for(int i=0;i<a[v].size();i++){
                pair<int,int> temp=a[v][i];
                int ver=temp.first;
                int weight=temp.second;
                if(dist[ver]>dist[v]+weight){
                    dist[ver]=dist[v]+weight;
                    pq.push(make_pair(dist[ver],ver));
                }
            }
        }
        
        for(i=0;i<n;i++)
        cout<<dist[i]<<" ";
    
        
    }
	
	
	return 0;
}
