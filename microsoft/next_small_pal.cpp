//Given a number, find the next smallest palindrome larger than this number. For example, if the input number is “2 3 5 4 5”, 
//the output should be “2 3 6 3 2”. And if the input number is “9 9 9”, the output should be “1 0 0 1”.

#include <iostream>
using namespace std;

int are_all_9s(string s){
    int i;
    for(i=0;i<s.size();i++){
        if(s[i]!='9')
        return 0;
    }
    return 1;
}
string generate_pal(string s){
    
    int mid =s.size()/2;
    int i=mid-1;
    int j=(s.size()%2==1)?mid+1:mid;
    while(i>=0&&s[i]==s[j]){
        i--;j++;
    }
    int small=0;
    if(i<0||s[i]-48<s[j]-48)
        small=1;
    
    while(i>=0){
        s[j]=s[i];
        i--;
        j++;
    }
    int carry=1;
    if(small==1){
         
        i=mid-1;
        if(s.size()%2==1){
            int x=s[mid]-48 +carry;
            char ch=x%10+48;
            s[mid]=ch;
            carry = x/10;
            j=mid+1;
        }
        else 
        j=mid;
    }
    cout<<carry<<endl;
    while(i>=0){
        int x = s[i]-48 + carry;
        //cout<<x;
        char ch=x%10 + 48;
        s[i] = ch;
        carry=x/10;
        s[j]=s[i];
        i--;j++;
    }
    
return s;
    
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s;
        int c=are_all_9s(s);
        if(c==1){
            cout<<1;
            for(int i=1;i<s.size();i++){
                cout<<0;
            }
            cout<<1;
        }
        else{
            t=generate_pal(s);
        }
                
        cout<<t<<endl;
    }
	return 0;
}
