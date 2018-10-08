//Given a 2D grid of characters and a word, find all occurrences of given word in grid. 
//A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match
//in this direction (not in zig-zag form).
//The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up and 4 Diagonal directions.


#include <iostream>
using namespace std;
char grid[3][14] = {"GEEKSFORGEEKS","GEEKSQUIZGEEK","IDEQAPRACTICE"}; 
int n,m;
bool search_(int x,int y,string s){
    if(s[0]!=grid[x][y])
        return false;
    
    int xx[]={-1,0,-1,1,0,1,-1,1};
    int yy[]={-1,-1,0,0,1,1,1,-1};
    int i,k;
    for(i=0;i<8;i++){
        int newx = x + xx[i];
        int newy = y + yy[i];
        
        for(k=1;k<s.size();k++){
            
            if(newx<0||newx>=n||newy<0||newy>=m)
                break;
           
            else if(grid[newx][newy]!=s[k])
                break;
            
           else if(grid[newx][newy]==s[k]){
                newx = newx+xx[i];
                newy = newy+yy[i];
            }
            
        }
        
    //   cout<<k<<endl;
        if(k==s.size())
            return true;
        
    }
    
   return false; 
}
int main() {
    int i,j;
    n=3,m=14;
    string word="GEEK";
    // char grid[n][m] = ;
    
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++)
    //     cin>>a[i][j];
    // }
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(search_(i,j,word)){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    
	return 0;
}
