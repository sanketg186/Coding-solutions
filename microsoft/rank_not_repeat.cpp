//Given a string, find its rank among all its permutations sorted lexicographically. 
//For example, rank of “abc” is 1, rank of “acb” is 2, and rank of “cba” is 6. 

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==1||n==0)
    return 1;
    return n*fact(n-1);
    
}
int main() {
	string s;
	int i;
	cin>>s;
	int mul=fact(s.size());
	vector<int>aux(256,0);
	for(i=0;i<s.size();i++)
	    aux[s[i]]++;
	for(i=1;i<256;i++){
	    aux[i]+=aux[i-1];
	}
	int rank=1;
	for(i=0;i<s.size();i++){
	    mul/=(s.size()-i);
	    rank+=aux[s[i]-1]*mul;
	    for(int j=s[i];j<256;j++)
	        aux[j]--;
	    
	}
	cout<<rank<<endl;
	return 0;
}
