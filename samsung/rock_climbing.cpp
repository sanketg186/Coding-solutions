question link:https://drive.google.com/drive/folders/0B_vP6PhDSlhOODVibWhLRU0yWUU
//Mr. K has a mania afor rock climbing.
//Mr. K who comleted several rock-climbing courses in the past now wants to go for a course which is known to be tough and hard.
//N us height and M is width of the rock.

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
