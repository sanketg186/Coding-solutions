#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int i,n,j;
    cin>>n;
    vector<int>a(n,0);
    for(i=0;i<n;i++)
        cin>>a[i];
    i=0,j=n-1;
    int cur_area,max_area=0;
    while(i<j){
        cur_area=(j-i-1)*min(a[i],a[j]);
        max_area=max(cur_area,max_area);
        if(a[j]<a[i])
            j--;
        else
            i++;
        
    }
    cout<<max_area<<endl;
	return 0;
}
