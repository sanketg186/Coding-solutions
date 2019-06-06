question link:https://drive.google.com/drive/folders/0B_vP6PhDSlhOODVibWhLRU0yWUU

/*
QUESTION:
FIND THE DIFFICULTY OF THE CLIMB.
Given a grid( nXm matrix) containing values 0,1,2 and 3.
0 represents no path.
1 represent an existing path.
2 is the starting point.
3 is the destination.
Starting point is always at left bottom matrix[n,1].
Destination can be anywhere in the matrix. It is assured that a path exist.
A rockclimber can move right or left if the adjacent element is also 1.
The rockclimber however climb up or down skip any number of rows the more rows he skip the greater will the difficulty.
*/
using namespace std;
int sx,sy,gx,gy,res_max=-1;
int num_steps,flag=0;
int is_safe(vector<vector<int>>v,int n,int m,int x,int y){
    if(x<n&&y<m&&x>=0&&y>=0&&v[x][y]!=0)
        return 1;
    return 0;
}
void dfs(vector<vector<int>>v,vector<vector<int>>visit,int x,int y,int cur_max,int n,int m){
    int i,j;
    if(flag==1)
    return;
    visit[x][y]=1;
    if(v[x][y]==3){
        
        res_max = max(res_max,cur_max);
        flag=1;
        return;
    }
    for(j=1;j<=num_steps;j++){
        
        if(is_safe(v,n,m,x+j,y)&&visit[x+j][y]==0){
            int temp = max(cur_max,j);
            dfs(v,visit,x+j,y,temp,n,m);
        }
        if(is_safe(v,n,m,x-j,y)&&visit[x-j][y]==0){
            int temp = max(cur_max,j);
            dfs(v,visit,x-j,y,temp,n,m);
        }
        if(is_safe(v,n,m,x,y+1)&&visit[x][y+1]==0){
            dfs(v,visit,x,y+1,cur_max,n,m);
        }
        if(is_safe(v,n,m,x,y-1)&&visit[x][y-1]==0){
            dfs(v,visit,x,y-1,cur_max,n,m);
        }
        
    }
    return;
    
}

int main() {
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m,0));
    vector<vector<int>>visit(n,vector<int>(m,0));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]==2){
                sx=i;
                sy=j;
            }
            if(v[i][j]==3){
                gx=i;
                gy=j;
            }
        }
    }
    visit[sx][sy]=1;
    for(i=1;i<=n;i++){
        res_max=0;
        num_steps=i;
        flag=0;
        dfs(v,visit,sx,sy,0,n,m);
        if(res_max>0)
            break;
    }
    cout<<res_max<<" ";
    
	return 0;
}
