
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        vector<int>a(n,0);
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        int exc=0;
        int inc=a[0];
        int cur1=0,cur2=0;
        for(i=1;i<n-1;i++){
            int new_exc=max(exc,inc);
            inc = exc+a[i];
            exc = new_exc;
        }
        cur1=max(inc,exc);
        exc=0;
        inc=a[1];
        for(i=2;i<n;i++){
            int new_exc=max(exc,inc);
            inc = exc+a[i];
            exc = new_exc;
        }
        cur2=max(inc,exc);
        cout<<max(cur1,cur2);
    }
	return 0;
}
