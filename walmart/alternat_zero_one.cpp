//Check if the binary representation of provided number is only made of alternate sequence of  1 and 0 or not . 
//For example : 2 => [10] => yes, 3 =>[11]=>No, 4=>[100]=>No, 5 =>[101]=>yes.
#include <iostream>
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {
    int n,temp;
    cin>>n;
    temp=n;
   
 
    int not_alternate=0;
    int flag=temp&1;
    while(temp!=0){
        int x=temp&1;
        if(flag!=x){
            not_alternate=1;
            break;
        }
        flag=1-x;
        temp=temp>>1;
    }
    if(not_alternate)
        cout<<"0"<<endl;
    else
        cout<<"1"<<endl;
	
	return 0;
}
