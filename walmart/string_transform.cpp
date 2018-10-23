
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

int pal_fun(string s,int bs,int be){
    int i=0,j=s.size()-1;
    int cost=0;
    //cout<<s<<endl;
    while(i<=j){
        if(s[i]!=s[j]){
        if(j>=bs&&j<=be)
            return 10000;
        else
            cost++;
        }
            i++;j--;
        
    }
    //cout<<cost<<endl;
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
	int bs=0,be=0;
	for(i=0;i+lb<sa.size();i++){
	    string temp=sa.substr(i,lb);
	    cost=convert(temp,sb);
	    mod="";
	    bs=i;
	    be=bs+lb-1;
	    if(i!=0)
	     mod=sa.substr(0,i);
	    mod=mod+sb;
	    string rem=sa.substr(i+lb,la-lb);
	    mod= mod+ rem;
	    pal_cost=pal_fun(mod,bs,be);
	    tot_cost=min(tot_cost,pal_cost+cost);
	}
	if(tot_cost>=10000)
	    cout<<"Not possible";
	else
	cout<<tot_cost<<endl;
	
	return 0;
}
