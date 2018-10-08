// A Research team want to establish a research center in a region where they found some rare-elements.They want to make
// it closest to all the rare-elements as close as possible so that they can reduce overall cost of research 
// over there.It is given that all the rare-element’s location is connected by roads.It is also given that Research
// Center can only be build on road.Team decided to assign this task to a coder.If you feel you have that much potential..
// Here is the Task :- Find the shortest of the longest distance of research center from given locations of rare-elements.

// locations are given in the matrix cell form where 1 represents roads and 0 no road..
// number of rare-element and their location was also given(number<=5)
// and order of square matrix was less than equal to (20).



#include <iostream>
using namespace std;
struct E{
  int x;
  int y;
};
int a[10][10],dist[10][10],n,m,num;
struct E e[10];

class Queue{
    public:
    E A[100000];
    int front,rear;
    Queue(){
        front=rear=0;
    }
    void push(E e){
        A[rear].x=e.x;
        A[rear].y=e.y;
        rear++;
    }
    
    E pop(){
        return A[front++];
    }
    
    bool empty(){
        return front>=rear?1:0;
    }
    
};
bool isvalid(int x,int y){
    if(x>=0 && x<n && y>=0 && y<n && a[x][y]==1)
        return 1;
    return 0;
}

void bfs(int x,int y){
    Queue q;
    struct E old;
    old.x=x;
    old.y=y;
    int visit[20][20];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        visit[i][j]=0;
    }
    q.push(old);
    dist[x][y]=0;
    visit[x][y]=1;
    int xx[]={1,0,-1,0};
    int yy[]={0,1,0,-1};
    while(!q.empty()){
        E n=q.pop();
        for(int i=0;i<4;i++){
            int xnew = n.x + xx[i];
            int ynew = n.y + yy[i];
            if(isvalid(xnew,ynew)&&!visit[xnew][ynew]){
                dist[xnew][ynew] = 1+ dist[n.x][n.y];
                E nn;
                nn.x = xnew;
                nn.y = ynew;
                visit[nn.x][nn.y]=1;
                q.push(nn);
            }
        }
        
    }
    
}
