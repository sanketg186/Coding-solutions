//sum of uncommon elements in two arrays

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int i,n,m;
	cin>>n>>m;
	vector<int>a(n,0),b(m,0);
	for(i=0;i<n;i++)
	    cin>>a[i];
	
	for(i=0;i<m;i++)
	    cin>>b[i];
	
	unordered_map<int,int>hash;
	int sum=0;
	for(i=0;i<n;i++){
	    sum+=a[i];
	    hash[a[i]]++;
	}
	
	for(i=0;i<m;i++){
	    if(hash.find(b[i])!=hash.end()){
	        sum=sum-b[i]*hash[b[i]];
	        hash[b[i]]=0;
	    }
	    else{
	        sum+=b[i];
	    }
	  
	    
	}
	cout<<sum<<endl;
	return 0;
}
