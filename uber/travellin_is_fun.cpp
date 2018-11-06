

int fin(int a,vector<int>&par){
    if(par[a]==a)
        return a;
    return fin(par[a],par);
}

void uni_(int a,int b,vector<int>&par){
    int x=fin(a,par);
    int y=fin(b,par);
    if(x<y)
        par[b]=x;
    else
        par[a]=y;
    
}

vector <int> connectedCities(int n, int g, vector <int> originCities, vector <int> destinationCities) {
    // Complete this function
    vector<int>par(n+1,0);
    int i,j;
    vector<int>res;
    for(i=1;i<=n;i++)
        par[i]=i;
    for(i=g+1;i<=n;i++){
        for(j=2*i;j<=n;j=j+i){
            if(fin(i,par)!=fin(j,par))
                uni_(i,j,par);
        }
    }
    
   for(i=0;i<originCities.size();i++){
       int a=originCities[i];
       int b=destinationCities[i];
       if(fin(a,par)==fin(b,par))
           res.push_back(1);
       else
           res.push_back(0);
   } 
    return res;
}
