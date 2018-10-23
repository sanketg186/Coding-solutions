//From 0 make X such that you can add, subtract and double. Cost of adding and subtracting is A whereas cost of doubling is B.
//Find minimum cost.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,i,a,b;
	cin>>n>>a>>b;
	vector<int>dp(2*n+1,INT_MAX);
	dp[1]=a;
	dp[0]=0;
	for(i=2;i<=n;i++){
	    if(i%2==0){
	        dp[i]=min(dp[i/2]+b,dp[i-1]+a);
	        if(i+1<=2*n&&dp[i+1]!=INT_MAX)
	            dp[i]=min(dp[i],dp[i+1]+a);
	    }
    else {
        dp[i]=min(dp[i-1]+a,dp[i]);
        if(i+1<=2*n&&dp[i+1]!=INT_MAX)
	       dp[i]=min(dp[i],dp[i+1]+a);
        }
    if(2*i<=2*n)
    dp[2*i]=dp[i]+b;
    if(2*i+1<=2*n)
    dp[2*i+1]=dp[i]+b+a;
	}
	
	cout<<dp[n]<<endl;
	return 0;
}
