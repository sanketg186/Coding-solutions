//Find the minimum cost of making a number sum of two single digit odd prime numbers with positive power.
//Calculate the cost where cost of increasing by 1 and cost of decreasing by 1 is provided.
//For example: Provided no is 4, increment cost 9 ,decrement cost 7, nearest no possible is 8 ,(3^1 + 5^1).
//So minimum  cost  = (8-4)*9 = 36.



#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,n,inc,dec;
	cin>>n>>inc>>dec;
	vector<int>v(2);
	v[0]=dec;
	v[1]=inc;
	a=ceil(log2(n)/log2(3));
	b=ceil(log2(n)/log2(5));
	c=ceil(log2(n)/log2(7));
	vector<int>va(a,0);
	vector<int>vb(b,0);
	vector<int>vc(c,0);
	int i,j;
	for(i=0;i<a;i++){
	    va[i]=pow(3,i+1);
	}
		for(i=0;i<b;i++){
	    vb[i]=pow(5,i+1);
	}
		for(i=0;i<c;i++){
	    vc[i]=pow(7,i+1);
	}
	
	i=0;
	j=b-1;
	int min_diff=INT_MAX,curr_diff;
	int sign=0;
	while(i<a&&j>=0){
	    int temp = va[i]+vb[j];
	    curr_diff=abs(temp-n);
	    if(min_diff>curr_diff){
	        if(temp>n)
	          sign=1;
	        else
	           sign=0;
	       min_diff=curr_diff;     
	    }
	    if(temp>n)
	    j--;
	    else if(temp<n)
	        i++;
	    else
	       break;
	}
	i=0;j=c-1;
		while(i<b&&j>=0){
	    int temp = vb[i]+vc[j];
	    curr_diff=abs(temp-n);
	    if(min_diff>curr_diff){
	        if(temp>n)
	          sign=1;
	        else
	           sign=0;
	       min_diff=curr_diff;     
	    }
	    if(temp>n)
	    j--;
	    else if(temp<n)
	        i++;
	    else
	       break;
	}
	i=0;j=c-1;
		while(i<a&&j>=0){
	    int temp = va[i]+vc[j];
	    curr_diff=abs(temp-n);
	    if(min_diff>curr_diff){
	        if(temp>n)
	          sign=1;
	        else
	           sign=0;
	       min_diff=curr_diff;     
	    }
	    if(temp>n)
	    j--;
	    else if(temp<n)
	        i++;
	    else
	       break;
	}
	
	cout<<min_diff<<" "<<min_diff*v[sign]<<" "<<sign<<endl;
	return 0;
}
