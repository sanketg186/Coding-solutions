// There are N fishing spots and 3 gates. At each gate there are some fishermen waiting to reach the nearest unoccupied fishing spot. (Total no of fisherman <=N)
// Distance between consecutive spots = distance between gate and nearest spot = 1 m
// Only 1 gate can be opened at a time and all fishermen of that gate must occupy the spots before the next gate is opened.
// Distance is calculated as gate to nearest spot + nearest spot to closest vacant spot.
// Find the total sum of minimum distances need to walk for all the fishermen.

// Inputs to be taken:
// Number of fishing spots
// Position of the gates
// Number of fishermen at each gates 


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,fisherman[10],gate[10];

int compute_cost(int gateno,int leftstart){
    
    int i,sum=0;
    for(i=leftstart;i<leftstart+fisherman[gateno];i++){
        sum = sum+abs(gate[gateno]-i)+1;
        
        
    }
    
    return sum;
    
}


int allocatefisherman(int gateno,int leftstart){
    
    if(gateno==m)
        return 0;
    if(leftstart+fisherman[gateno]>n-1)
    return 100000;
    
    int i;
    int min_dist=INT_MAX;
    for(i=leftstart;i<n;i++){
        int nextleft = i+fisherman[gateno];
        min_dist =min(min_dist,allocatefisherman(gateno+1,nextleft)+compute_cost(gateno,i));
    }
    
    return min_dist;
}


int main() {
	cin>>n>>m;
	int i;
	for(i=0;i<m;i++)
	    cin>>fisherman[i];
	    
	for(i=0;i<m;i++)
	    cin>>gate[i];
	
	int cost = allocatefisherman(0,0);
	cout<<cost<<endl;
	
	return 0;
}
