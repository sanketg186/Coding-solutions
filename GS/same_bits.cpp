//Given a positive integer n, print the next smallest and 
//the previous largest number that have the same number of 1 bits in their binary representation.
#include <iostream>
using namespace std;
int get_prev(int n){
	int c1=0,c=n,c0=0;
	while((c&1)==1){
		c1++;
		c=c>>1;
	}
	if(c==0)
		return -1;
	while((c&1)==0&&c!=0){
		c0++;
		c=c>>1;
	}
	// cout<<p<<endl;
	int p=c0+c1;
	n=n&(~0<<(p+1));
	int mask = (1<<(c1+1))-1;
	n=n|(mask<<(c0-1));
	return n;
}
int get_next(int n){
	int c=n,c0=0,c1=0;
	while(((c&1)==0)&&c!=0){
		c0++;
		c=c>>1;
	}
	while((c&1)==1){
		c1++;
		c=c>>1;
	}
	if(c0+c1==31||c0+c1==0)
		return -1;
		
	int p=c0+c1;
	n=n|(1<<p);
	n=n&(~((1<<p)-1));
	n=n|((1<<(c1-1))-1);
	return n;
}
int main() {
	int n;
	cin>>n;
	//cout<<get_next(n)<<endl;
	cout<<get_prev(n);
	// your code goes here
	return 0;
}
