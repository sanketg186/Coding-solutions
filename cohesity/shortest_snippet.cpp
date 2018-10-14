//You are given two strings​ ​S​ ​and​ ​Q.​ ​Each​ ​string​ ​has​ ​multiple​ ​words​ ​separated​ ​by​ ​single
//spaces.​ ​Each​ ​word​ ​in​ ​S​ ​is​ ​given​ ​an​ ​index,​ ​starting​ ​from​ ​0​ ​for​ ​the​ ​first​ ​word.​ ​You​ ​have​ ​to​ ​find​ ​the​ ​smallest
//range​ ​[l,r](both​ ​inclusive)​ ​in​ ​S​ ​which​ ​contains​ ​all​ ​words​ ​in​ ​Q

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;
     cin >> t;
    //  string st;
    //  getline(cin,st);
    //  cout << st <<endl;
     while(t--){
         int i,j,count=0;
         string s,p;
s="what about the lazy brown fox that jumped over the other brown one which lazy dog ate the food of the fox";   
p="lazy brown dog";
       //  getline(cin,s);
        //  getline(cin,p);
        //  cout<<s;
         
         vector<string>vs;
         vector<string>vp;
        //  cout<<s.size();
         int st=0;
         for(i=0;i<s.size();i++){
             if(isspace(s[i])){
                 string temp=s.substr(st,i-st);
                 vs.push_back(temp);
                 st=i+1;
                 
             }
             
         }
         
         vs.push_back(s.substr(st,i));
        //  for(i=0;i<vs.size();i++)
        //  cout<<vs[i]<<endl;
         st=0;
        for(i=0;i<p.size();i++){
             if(p[i]==' '){
                 string temp=p.substr(st,i-st);
                 vp.push_back(temp);
                 st=i+1;
             }
             
         }
         vp.push_back(p.substr(st,i));
         unordered_map<string,int>hash_pat,hash_str;
        //  hash_pat.clear();
        //  hash_str.clear();
         for(i=0;i<vp.size();i++){
             hash_pat[vp[i]]++;
         }
         int start=0,start_in=-1,min_length=INT_MAX;
         for(i=0;i<vs.size();i++){
             hash_str[vs[i]]++;
             
             if(hash_pat[vs[i]]!=0 && hash_str[vs[i]]<=hash_pat[vs[i]])
                 count++;
                
            if(count==vp.size()){
                
                while(hash_str[vs[start]]>hash_pat[vs[start]]||hash_pat[vs[start]]==0){
                    
                    if(hash_str[vs[start]]>hash_pat[vs[start]])
                     hash_str[vs[start]]--;
                     start++;
                }
                 
                 int len_wind=i-start+1;
                 if(min_length>len_wind){
                     min_length=len_wind;
                     start_in=start;
                 }
             }
             
         
         
     }
     cout<<min_length<<endl;
     }
	//code
	return 0;
}
