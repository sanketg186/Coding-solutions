bool isvalid(int i,int j,int n,int m,int A[MAX][MAX]){
    if(i<0||i>=n||j<0||j>=m||A[i][j]==0)
        return false;
    return true;
}

void dfs(int A[MAX][MAX],int N,int M,vector<vector<bool>>&visit,int i,int j){
    visit[i][j]=true;
    if(isvalid(i+1,j,N,M,A)&&(!visit[i+1][j]))
        dfs(A,N,M,visit,i+1,j);
        
    if(isvalid(i-1,j,N,M,A)&&(!visit[i-1][j]))
        dfs(A,N,M,visit,i-1,j);
        
    if(isvalid(i,j+1,N,M,A)&&(!visit[i][j+1]))
        dfs(A,N,M,visit,i,j+1);
        
    if(isvalid(i,j-1,N,M,A)&&(!visit[i][j-1]))
        dfs(A,N,M,visit,i,j-1);
    
    if(isvalid(i-1,j-1,N,M,A)&&(!visit[i-1][j-1]))
        dfs(A,N,M,visit,i-1,j-1);
    if(isvalid(i+1,j+1,N,M,A)&&(!visit[i+1][j+1]))
        dfs(A,N,M,visit,i+1,j+1);
    if(isvalid(i+1,j-1,N,M,A)&&(!visit[i+1][j-1]))
        dfs(A,N,M,visit,i+1,j-1);
    if(isvalid(i-1,j+1,N,M,A)&&(!visit[i-1][j+1]))
        dfs(A,N,M,visit,i-1,j+1);
        
    return ;
}
int findIslands(int A[MAX][MAX], int N, int M)
{
    vector<vector<bool>>visit(N,vector<bool>(M,false));
    int i,j;
    int c=0;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(visit[i][j]==false&&A[i][j]==1){
                c++;
                dfs(A,N,M,visit,i,j);
            }
                
        }
    }
    return c;
