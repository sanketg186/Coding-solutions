//You have a matrix of 0 and 1 of order N*M and a parameter K is given.
//You have to perform the operation of flipping any column of matrix exactly K times.
//Flipping means changing 0 to 1 and 1 to 0. This operation can be performed any number of times on the same column. 
//Using this operation, maximize number of rows filled with all 1.
//First line is number of test cases, next line is N, M and K, and then N*M matrix follows.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int cmp(pair<int,int>a,pair<int,int>b){
    if(a.first>b.first)
        return 1;
    else
    return 0;
}

int main() {
	int i,j,n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>>v(n,vector<int>(m,0));
	unordered_map<string,pair<int,int>> hash;
// 	hash.clear();
	for(i=0;i<n;i++){
	string s="";
	int num_zero=0;
	    for(j=0;j<m;j++){
	        cin>>v[i][j];
	        s=s+to_string(v[i][j]);
	        if(v[i][j]==0)
	            num_zero++;
	    }
	hash[s].first +=1;
	hash[s].second=num_zero;
	}
// 	sort(hash.begin(),hash.end(),cmp);
	int res=0;
	for(auto it=hash.begin();it!=hash.end();it++){
	   cout<<it->first<<" "<<(it->second).first<<" "<<(it->second).second<<endl;
	    if(((it->second).second)==k){
	        res=max((it->second).first,res);
	    }
	    else if((it->second).second<k&&(k-(it->second).second)%2==0){
	        res=max((it->second).first,res);
	    }
	}
	cout<<res;
	return 0;
}
