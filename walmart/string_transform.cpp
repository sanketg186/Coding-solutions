
// String A and B are given. Minimum Manipulation done in string A to make string A a palindrome 
//if not and make sure that B is present as a substring in A. (40 M)
//I/P-    A=aaaaa ,B=bbb       O/P-    3
//I/P-    A=archit ,B=ar        O/P-  3



#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int convert(string a,string b){
    int i=0,j=0;
    int cost=0;
    while(i<a.size()){
        if(a[i]!=b[i])
            cost++;
            i++;
    }
    return cost;
}

int pal_fun(string s){
    int i=0,j=s.size()-1;
    int cost=0;
    while(i<=j){
        if(s[i]!=s[j])
            cost++;
            i++;j--;
    }
    
    return cost;
}
int main() {
	int i,j;
	string sa,sb;
	cin>>sa>>sb;
	
	int lb=sb.size();
	int la=sa.size();
	int cost;
	int pal_cost;
	int tot_cost=INT_MAX;
	string mod;
	for(i=0;i+lb<sa.size();i++){
	    string temp=sa.substr(i,lb);
	    cost=convert(temp,sb);
	    mod="";
	    if(i!=0)
	    mod=sa.substr(0,i);
	    mod=mod+temp;
	    string rem=sa.substr(i+lb,la-lb);
	    mod= mod+ rem;
	    pal_cost=pal_fun(mod);
	    tot_cost=min(tot_cost,pal_cost+cost);
	}
	cout<<tot_cost<<endl;
	
	return 0;
}
