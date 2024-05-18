#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a=0,b;
    int n;
    cin>>b>>n;
    string s="",s1="";
    for(int i=0;i<=n;i++){
        a+=b;
        s+=to_string(a%10);
        a/=10;
    }
    s1+=to_string(a);
    reverse(s1.begin(),s1.end());
    s+=s1;
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}