#include <iostream>
using namespace std;
int a[20][20];
int visit[20];
int max_c=10000;
void tsp(int in,int n,int cost,int count){
    
    if(count==n-2){
        max_c=min(cost+a[in][1],max_c);
        return;
    }
    for(int i=2;i<n;i++){
        if(!visit[i]){
            visit[i]=true;
            if(count==0){
                tsp(i,n,cost+a[0][i],count+1);
            }
            else{
                
            tsp(i,n,cost+a[in][i],count+1);
            }
            visit[i]=false;
        }
    }
    
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int i,j,n,m;
	    cin>>n>>m;
	    n=n+2;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                a[i][j]=0;
                visit[i]=0;
            }
     
     m=m+2;
	 int x[m],y[m];
	 for(i=0;i<m;i++){
	     cin>>x[i]>>y[i];
	 }
	 for(i=0;i<m;i++){
	     for(j=i+1;j<m;j++){
	         a[j][i]=a[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
	         
	     }
	 }
	 
	 tsp(2,n,0,0);
	 cout<<max_c<<endl;
	
	
	
	   
	}
	
	return 0;
}
