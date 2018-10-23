 //How many K length string can be made if you can use exactly P alphabets from given X alphabets and exactly Q digits 
 //from dgiven Y digits.You are given values of K, X, Y, P, Q. 
#include <iostream>
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int ncr(int n,int k){
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=min(i,k);j++){
            if(j==0||j==i)
            dp[i][j]=1;
            else 
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
        }
    }
    return dp[n][k];
}

int pow(int n,int x){
    if(x==0)
    return 1;
    if(x==1)
    return n;
    if(n%2==0){
        int a=pow(n,x/2);
        return (a%mod*a%mod)%mod;
    }
    if(n%2==1){
        int b=pow(n,x/2);
        return ((b%mod*b%mod)%mod*b)%mod;
    }
    
}
int main() {
      int x,y,k,p,q;
      cin>>x>>y>>k>>p>>q;
      
      long long a=ncr(k-1,q);
    //   cout<<a<<endl;
      long long b=pow(x,p);
      long long c=pow(y,q);
      cout<<(((a%mod)*(b%mod))%mod*(c%mod))%mod<<endl;
    
    
	return 0;
}





// #include <iostream>
// using namespace std;
// int res=0;
// void recur(int p,int q,int k,int x,int y){
//     int i;
//     if(p==0&&q==0&&k==0){
//         res++;
//         return;
//     }
//     if(k==0){
//         return;
//     }
    
    
//     if(p>0)
//     for(i=0;i<x;i++)
//         recur(p-1,q,k-1,x,y);
    
 
//     if(q>0)
//       for(i=0;i<y;i++)
//         recur(p,q-1,k-1,x,y);
    
// }
// int main() {
// 	int k,x,y,p,q,i;
// 	int tot=0;
// 	cin>>x>>y>>k>>p>>q;
// 	for(i=0;i<x;i++){
// 	    recur(p-1,q,k-1,x,y);
	   
// 	}
// 	cout<<res<<endl;
// 	return 0;
// }
