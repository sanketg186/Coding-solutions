#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool check_palindrome(string s){
    string temp=s;
    reverse(temp.begin(),temp.end());
    if(temp==s)
    return 1;
    else 
    return 0;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string rem="";
        if(s.size()==0||check_palindrome(s))
        cout<<0<<endl;
        else{
            while(!check_palindrome(s)){
                rem=rem+s[0];
                s.erase(s.begin());
            }
            
            cout<<rem.size()<<endl;
        }
        
    }
	return 0;
}
