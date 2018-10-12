//Reorder an array according to given indexes
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
	int n,i;
	cin>>n;
	vector<int>a(n,0),in(n,0);
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	cin>>in[i];
	
	for(i=0;i<n;i++){
	    
	    while(in[i]!=i){
	        
	        int oi=in[in[i]];
	        int ot=a[in[i]];
	        
	        a[in[i]]=a[i];
	        in[in[i]]=in[i];
	        a[i]=ot;
	        in[i]=oi;
	    }
	}
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}
