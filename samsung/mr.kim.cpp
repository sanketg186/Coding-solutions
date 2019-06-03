//Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to 
//his home. Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) 
//(0≤x≤100, 0≤y≤100) . The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|,
//where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. The locations of the office, his home, and the customers 
//are all distinct. You should plan an optimal way to visit all the N customers and return to his among all the //
//possibilities. 

//You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 
//5 to 10. Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to 
//his home. Your program only have to report the distance of a (the) shortest path. 

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int i,n,x,y,cur_dist=0,min_dist=INT_MAX,office_x,office_y,home_x,home_y;
	cin >> n;
	vector<pair<int,int>>v;
	vector<int>num(n);
	cin>>office_x>>office_y;
	cin>>home_x>>home_y;
	for(i=0;i<n;i++){
	    num[i]=i;
	    cin>>x>>y;
	    v.push_back(make_pair(x,y));
	}
	
	do{
	   // for(i=0;i<v.size();i++)
	   // cout<<v[i].first<<" "<<v[i].second<<":";
	   // cout<<endl;
	    cur_dist=abs(office_x-v[num[0]].first)+abs(office_y-v[num[0]].second);
	    
	    for(i=1;i<v.size();i++){
	        cur_dist+=abs(v[num[i-1]].first-v[num[i]].first) + abs(v[num[i-1]].second-v[num[i]].second);
	    }
	    cur_dist = cur_dist + abs(v[num[num.size()-1]].first-home_x) + abs(v[num[num.size()-1]].second-home_y);
	    min_dist = min(cur_dist,min_dist);
	}while(next_permutation(num.begin(),num.end()));
	
	cout<<min_dist<<endl;
	return 0;
}
