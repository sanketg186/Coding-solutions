//Given an array representing n positions along a straight line. Find k 
//(where k <= n) elements from the array such that the maximum distance between any two (consecutive points among the k points) 
//is maximized

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int k;

int num_stu(int a[],int mid,int n){
    int i;
    // int sum=0;
    int pos = a[0];
    int num=1;  
    for(i=1;i<n;i++){
        if(a[i]-pos>=mid){
            num++;
            pos=a[i];
        }
        if(num==k)
        return 1;
       
    }
    
    return 0;
}

int main() {
    int i,n,m;
    int mid;
    cin>>n>>m;
    int a[m],sum=0;
    for(i=0;i<m;i++){
        cin>>a[i];
    }
    sort(a,a+m);
    k=n;
    int lo=a[0],hi=a[m-1];
    int res=0;
    while(lo<hi){
        
        mid = (lo+hi)/2;
        int num=num_stu(a,mid,m);
        if(num==1){
            lo = mid+1;
            res=max(mid,res);
        }
        else
            hi = mid;
        
    }
    
    cout<<res<<endl;
    
    
	return 0;
}
