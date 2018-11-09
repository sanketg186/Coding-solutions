#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,i,steps,max_reach,min_jump=1;
    cin>>n;
    vector<int>a(n,0),dp(n+1,0);
    for(i=0;i<n;i++)
        cin>>a[i];
    
    steps=a[0];
    max_reach=a[0];
    for(i=1;i<n;i++){
        max_reach=max(max_reach,a[i]+i);
        dp[i]=min_jump;
        steps--;
        if(steps==0){
            steps=max_reach-i;
            min_jump++;
        }
    }
    dp[n]=min_jump;
    int q,qi;
    cin>>q;
    for(i=0;i<q;i++){
        cin>>qi;
        cout<<dp[qi]<<" ";
        
    }
    
	return 0;
}













// int main() {
//     int t;
//     cin>>t;
//     while(t--){
//         int n,i,j;
//         cin>>n;
//         vector<int>a(n,0);
//         vector<pair<int,int>>adj[n+1];
//         for(i=0;i<n;i++)
//             cin>>a[i];
//         for(i=0;i<n;i++){
//             for(j=1;j<=a[i];j++){
//                 adj[i].push_back(make_pair(i+j,1));
//                 adj[i+j].push_back(make_pair(i,1));
//             }
//         }
        
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         vector<int>dist(n+1,INT_MAX);
//         dist[0]=0;
//         pq.push(make_pair(0,0));
//         while(!pq.empty()){
//             int v=pq.top().second;
//             pq.pop();
            
//             for(i=0;i<adj[v].size();i++){
//                 pair<int,int>temp=adj[v][i];
//                 int vert=temp.first;
//                 int w=temp.second;
//                 if(dist[vert]>dist[v]+w){
//                     dist[vert]=dist[v]+w;
//                     pq.push(make_pair(dist[vert],vert));
//                 }
//             }
//         }
//         int q,qi;
//         cin>>q;
//         for(i=0;i<q;i++){
//             cin>>qi;
//             cout<<dist[qi]<<endl;
//         }
//     }
// 	return 0;
// }
