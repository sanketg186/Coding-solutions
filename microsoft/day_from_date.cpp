#include <iostream>
using namespace std;
int day_month(int m){
    switch(m){
    case 1:return 0;
    case 2:return 31;
    case 3:return 31+28;
    case 4:return 31+28+31;
    case 5:return 31+28+31+30;
    case 6:return 31+28+31+30+31;
    case 7:return 31+28+31+30+31+30;
    case 8:return 31+28+31+30+31+30+31;
    case 9:return 31+28+31+30+31+30+31+31;
    case 10:return 31+28+31+30+31+30+31+31+30;
    case 11:return 31+28+31+30+31+30+31+31+30+31;
    case 12:return 31+28+31+30+31+30+31+31+30+31+30;
}
}
int days(int d,int m){
    
    return d+day_month(m);
    
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int d,m,y;
        int temp;
        scanf("%d/%d/%d",&d,&m,&y);
        //cout<<d<<" "<<m<<" "<<y; 
        if(m>=2){
            temp=(y/4) -(y/100)+(y/400); 
        }
        else{
            temp=((y-1)/4) -((y-1)/100)+((y-1)/400);
        }
        int diff=y*365+temp+days(d,m) -726833+1;
        cout<<diff%7;
        
        
    }
    
	return 0;
}
