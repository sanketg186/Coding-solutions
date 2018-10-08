// n the grid above,
// 1: This cell has a coin.
// 2: This cell has an enemy.
// 0: It contains nothing.
// The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get maximum coins.
// Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
// At each time, the non-highlighted part of the grid will move down by one unit.
// We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone will be killed.



#include <iostream>
using namespace std;
int n,m;
int a[100][100];
int recur(int x,int y,int bomb){
    int coins=0;
    if(x==n)
    return 0;
    if(y<0||y>=5)
    return 0;
    if(a[x][y]==2){
        return 0;
    }
    else if(a[x][y]==1)
        coins =1;
    int c1=coins+recur(x+1,y-1,bomb);
    int c2=coins+recur(x+1,y+1,bomb);
    int c3=coins+recur(x+1,y,bomb);
    int c4,c5,c6,f=0,r1=0,r2=0;
    if(bomb==1){
    bomb=0;
    for(int i=x+1;i<x+6;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]==2)
            a[i][j]=3;
        }
    }
     c4=coins+recur(x+1,y-1,0);
     c5=coins+recur(x+1,y+1,0);
     c6=coins+recur(x+1,y,0);
    for(int i=x+1;i<x+6;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]==3)
            a[i][j]=2;
        }
    }
    
    r2=max(c4,max(c4,c6));
    }
    
    r1=max(c1,max(c2,c3));
    int max_cost=max(r1,r2);
    return max_cost;
    
    
}
int main() {
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<5;j++){
            cin>>a[i][j];   
        }
    }
    int bomb=1;
    int c=recur(0,2,1);
    cout<<c<<endl;
    
	return 0;
}
