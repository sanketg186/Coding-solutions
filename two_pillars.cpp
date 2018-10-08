#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int exist(int visit[],int a[],int n,int k){
    int s=0,i;
    for(i=0;i<n;i++){
        if(visit[i]==0)
            s+=a[i];
    }
    if(s==k)
        return 1;
    return 0;
}
int main() {
    int n,i,j,k;
    cin>>n;
    int a[n],sum=0;
    for(i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum=sum/2;
    int dp[n+1][sum+1];
    for(i=0;i<=n;i++)
    dp[i][0]=1;
    for(i=1;i<=sum;i++)
    dp[0][i]=0;
    
    for(i=1;i<=n;i++){
        for(j=1;j<=sum;j++){
            if(j<a[i-1])
                dp[i][j] = dp[i-1][j];
            else if(j>=a[i-1]){
                dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
            }
        }
        
    }
  
    for(k=sum;k>=0;k--){
        int visit[n];
        for(i=0;i<n;i++)
        visit[i]=0;
        if(dp[n][k]==1){
            int i=n,j=k;
            while(i>=0&&j!=0){
                if(dp[i-1][j]==1){
                    i--;
                }
                else{
                    visit[i-1]=1;
                    j=j-a[i-1];
                    i--;
                }
                
            }
            
            int tot = exist(visit,a,n,k);
            if(tot==1){
                cout<<k;
                break;
            }
           
            
        }
        
    }
	
	
	return 0;
}
