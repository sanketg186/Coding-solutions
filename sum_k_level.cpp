//Given an integer ‘K’ and a binary tree in string format. Every node of a tree has value in range from 0 to 9. 
//We need to find sum of elements at K-th level from root. The root is at level 0



#include <iostream>
using namespace std;
int res=0;

int main() {
    int i,k,level=-1;
    string s;
    cin>>k>>s;
    for(i=0;i<s.size();i++){
        if(s[i]=='(')
            level++;
        
        else if(s[i]==')')
            level--;
        
        else {
            if(level==k){
                res = res+s[i]-48;
            }
        }
        
        
    }
    cout<<res<<endl;
	return 0;
}
