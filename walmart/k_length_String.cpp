 //How many K length string can be made if you can use exactly P alphabets from given X alphabets and exactly Q digits 
 //from dgiven Y digits.You are given values of K, X, Y, P, Q. 

#include <iostream>
using namespace std;
int res=0;
void recur(int p,int q,int k,int x,int y){
    int i;
    if(p==0&&q==0&&k==0){
        res++;
        return;
    }
    if(k==0){
        return;
    }
    
    
    if(p>0)
    for(i=0;i<x;i++)
        recur(p-1,q,k-1,x,y);
    
 
    if(q>0)
      for(i=0;i<y;i++)
        recur(p,q-1,k-1,x,y);
    
}
int main() {
	int k,x,y,p,q,i;
	int tot=0;
	cin>>x>>y>>k>>p>>q;
	for(i=0;i<x;i++){
	    recur(p-1,q,k-1,x,y);
	   
	}
	cout<<res<<endl;
	return 0;
}
