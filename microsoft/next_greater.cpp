//A string is given. Minimum no. of characters to append to the string such that it will become palindrome. Print them.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t,i;
     cin>>t;
     while(t--){
    //  string s;
     int n;
     cin>>n;
     vector<int>a(n,0);
     for(i=0;i<n;i++)
     cin>>a[i];
     //cin>>s;
     int x=0,b,f=0;
     for(i=n-1;i>=1;i--){
        if(a[i-1]<a[i]){
            x=i-1;
            f=1;
            break;
        }
           
     }
     if(f==1){
     i=n-1;
     while(a[x]>=a[i]){
     i--;
     }
     swap(a[x],a[i]);
     if(x+1!=n-1) 
     sort(a.begin()+x+1,a.end());
     }
     else
     sort(a.begin(),a.end());
     
     for(i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;     
     }
     
	//code
	return 0;
}
