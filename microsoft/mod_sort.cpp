//Given an array of n elements and an integer k. Group the elements in k. And then sort the array.
 //   Ex: [1, 23, 4, 3, 8, 9] and k = 2. So number formed are 123, 43, 89. 
  //  Now after  sorting, it will be 43, 89, 123. SO return the array as [4,3,8,9,1,23]

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int cmp(vector<string>a,vector<string>b){
    string s1="",s2="";
    int i;
    for(i=0;i<a.size();i++)
        s1=s1+a[i];
        for(i=0;i<b.size();i++)
        s2=s2+b[i];
    if(s1.size()<s2.size())
        return 1;
    if(s1.size()>s2.size())
    return 0;
    if(s1.size()==s2.size())
    return lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end());
}
int main() {
	int t,n,k,i,j;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    vector<int>a(n,0);
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    vector<vector<string>>v;
	    int temp=k;
	     vector<string>vt;
	    for(i=0;i<n;i++){
	       
	       if(temp>0){
	           vt.push_back(to_string(a[i]));
	           temp--;
	       }
	       if(temp==0||i==n-1){
	        v.push_back(vt);
	        temp=k;
	        vt.clear();
	        }
	       }
	       
	       sort(v.begin(),v.end(),cmp);
	       for(i=0;i<v.size();i++){
	           for(j=0;j<v[i].size();j++){
	               cout<<v[i][j]<<" ";
	           }
	       }
	    
	}
	return 0;
}
