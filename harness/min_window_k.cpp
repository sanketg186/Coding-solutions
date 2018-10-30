
//minimum of all windows of size k
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	   int n,k,i;
	   cin>>n>>k;
	   vector<int>arr(n,0);
	   for(i=0;i<n;i++){
	       cin>>arr[i];
	   }
	 deque<int>dq;
	 for(i=0;i<k;i++){
	     
	     while(!dq.empty()&&arr[i]>=arr[dq.back()])
	     dq.pop_back();
	     dq.push_back(i);
	 }
	 
	 for(;i<n;i++){
	     cout<<arr[dq.front()]<<" ";
	     while(!dq.empty()&&dq.front()<=i-k)
	     dq.pop_front();
	     while(!dq.empty()&&arr[i]>=arr[dq.back()])
	     dq.pop_back();
	     dq.push_back(i);
	 }
	 while(!dq.empty()){
	     cout<<arr[dq.front()]<<" ";
	     dq.pop_front();
	 }
	 
	}
	return 0;
}
