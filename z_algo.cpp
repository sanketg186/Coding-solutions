#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void compute_z(string s,vector<int>&z){
	int k,left,right;
	for(k=1;k<s.size();k++){
		
		if(k>right){
			left=right=k;
			while(right<s.size()&&s[right]==s[right-left]){
				right++;
			}
			z[k]=right-left;
			right--;
		}
		
		else{
			int k1=k-left;
			if(z[k1]<right-k+1)
				z[k]=z[k1];
			else{
					left=right=k;
					while(right<s.size()&&s[right]==s[right-left]){
						right++;
					}
					z[k]=right-left;
					right--;
				}
			
		}
	
	}
}

int main() {
	string s;
	int n,i;
	cin>>s;
	n=s.size();
	vector<int>z(n,0);
	compute_z(s,z);
	int sum=0;
	for(i=0;i<n;i++){
		sum=sum+z[i];
	}
	for(i=0;i<n;i++)
	cout<<z[i]<<" ";
	cout<<sum+n<<endl;
	// your code goes here
	return 0;
}
