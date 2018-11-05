//Vasya follows a basketball game and marks the distances from which each team makes a throw. He knows that each successful throw 
//has value of either 2 or 3 points.A throw is worth 2 points if the distance it was made from doesn't exceed some value of d 
//meters, and a throw is worth 3 points if the distance is larger than d meters, where d is some non-negative integer.
//Vasya would like the advantage of the points scored by the first team (the points of the first team minus the points of the second
//team) to be maximum. For that he can mentally choose the value of d. Help him to do that.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int i,j,n,m,x;
	cin>>n>>m;
	vector<int>a,b;
	for(i=0;i<n;i++){
	    cin>>x;
	a.push_back(x);
	}
	for(i=0;i<m;i++){
	cin>>x;
	b.push_back(x);
	}
	a.push_back(INT_MAX);
	b.push_back(INT_MAX);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	i=0;j=0;
	int score_a=3*n,score_b=3*m;
	int max_diff=score_a-score_b;
	int maxa=score_a,maxb=score_b;
	while(i<n||j<m){
	    if(a[i]<b[j]){
	        score_a--;
	        i++;
	    }
	    else if(a[i]>b[j]){
	        score_b--;
	        j++;
	    }
	    else{
	        score_a--;
	        score_b--;
	        i++;j++;
	    }
	   if(max_diff<score_a-score_b){
	       max_diff=score_a-score_b;
	       maxa=score_a;
	       maxb=score_b;
	   } 
	 
	}
	cout<<maxa<<":"<<maxb<<endl;
	return 0;
}
