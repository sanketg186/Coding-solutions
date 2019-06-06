/*
Initially you have H amount of energy and D distance to travel. You may travel
with any of the given 5 speeds. But you may only travel in units of 1 km. For 
each km distance traveled, you will spend corresponding amount of energy.
e.g. the given speeds are:
Cost of traveling 1 km: [4, 5, 2, 3, 6]
Time taken to travel 1 km: [200, 210, 230, 235, 215]
Find minimum time required to cover total D km with remaining H >= 0
1 <= H <= 4000
1 <= D <= 1000
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp(4000,vector<int>(1000,-1));

int recur(int h,int d,int k,vector<int>c,vector<int>t){
    if(h<0) return 10000000;
    if(d==0) return 0;
    if(k<0) return 10000000;
    if(dp[h][d]!=-1)
        return dp[h][d];
    return dp[h][d] = min(recur(h,d,k-1,c,t),t[k]+recur(h-c[k],d-1,k,c,t));
}
int main() {
    int H,D,i;
    vector<int>cost(5,0),tim(5,0);
    cin>>H>>D;
    for(i=0;i<5;i++){
        cin>>cost[i];
    }
    for(i=0;i<5;i++){
        cin>>tim[i];
    }
    int res = recur(H,D,4,cost,tim);
    cout<<res;
	return 0;
}
