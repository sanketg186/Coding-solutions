//longest palindromic substring
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;
     cin>>t;
     while(t--){
         string s;
         int st=0,e=0;
         cin>>s;
         int n=s.size();
        
         vector<vector<bool>>tab(n+1,vector<bool>(n+1,false));
         int max_len=1;
         int i,j;
         for(i=1;i<=n;i++)
         tab[i][i]=true;
         for(i=1;i<n;i++){
             if(s[i-1]==s[i]){
                tab[i][i+1]=true;
                if(max_len<2){
                max_len=2;
                st=i-1;
                }
             }
         }
    
         for(int k=3;k<=n;k++){
             
             for(i=1;i<=n-k+1;i++){
               j=i+k-1;
               if(tab[i+1][j-1]==1&&s[i-1]==s[j-1]){
                    tab[i][j]=true;
                    if(k>max_len){
                    max_len=k;
                    st=i-1;
                    }
               }
             }
             
         }
         string res="";
         for(i=st;i<st+max_len;i++)
         res.push_back(s[i]);
         cout<<res<<endl;
         
         
     }
	//code
	return 0;
}
