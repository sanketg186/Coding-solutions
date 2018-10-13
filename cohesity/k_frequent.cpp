//kth most frequent
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int cmp(pair<char,int>a,pair<char,int>b){
    if(a.second>b.second)
        return 1;
    else if(a.second==b.second){
        if(a.first<b.first)
            return 1;
        else
        return 0;
    }
    return 0;
}
int main() {
    int t,i;
    cin>>t;
    while(t--){
       string s;
       int i,k;
       cin>>s>>k;
       unordered_map<char,int>hash;

       for(i=0;i<s.size();i++){
          hash[s[i]]++;
       }
        vector<pair<char,int>>v;       
       for(auto it=hash.begin();it!=hash.end();it++){
            v.push_back(make_pair(it->first,it->second));
       }
       sort(v.begin(),v.end(),cmp);
       
       vector<char>res;
       res.push_back(v[0].first);
       for(i=1;i<v.size();i++){
          if(v[i].second!=v[i-1].second)
          res.push_back(v[i].first);
       }
     
        if(k>res.size())
        cout<<-1<<endl;
        else
        cout<<res[k-1]<<endl;
  
       
    }
	return 0;
}
