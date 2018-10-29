//Consider an array A[] of integers and following two types of queries.

 //   update(l, r, x) : Adds x to all values from A[l] to A[r] (both inclusive).
  //  printArray() : Prints the current modified array.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void update(vector<int>&diff,int l,int r,int x){
    diff[l]=diff[l]+x;
    diff[r+1]=diff[r+1]-x;
}
int printArray(vector<int>& A, vector<int>& D) 
{ 
    for (int i = 0; i < A.size(); i++) { 
        if (i == 0) 
            A[i] = D[i]; 
  
        // Note that A[0] or D[0] decides 
        // values of rest of the elements. 
        else
            A[i] = D[i] + A[i - 1]; 
  
        cout << A[i] << " "; 
    } 
    cout << endl; 
} 
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    cin>>n;
	    vector<int>arr(n,0);
	    for(i=0;i<n;i++)
	        cin>>arr[i];
	    vector<int>diff(n+1,0);
	    diff[0]=arr[0];
	    for(i=1;i<n;i++){
	        diff[i]=arr[i]-arr[i-1];
	    }
	    update(diff,0,1,10);
	    for(i=0;i<n;i++)
	    cout<<diff[i]<<" ";
	    printArray(arr, diff); 
	    update(diff, 1, 3, 20); 
        update(diff, 2, 2, 30); 
        printArray(arr, diff); 
	    
	    
	}
	return 0;
}
