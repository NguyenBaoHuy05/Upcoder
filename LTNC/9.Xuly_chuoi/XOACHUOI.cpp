#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,k;
    getline(cin,s);
    getline(cin,k);
    int dem=0;
    for(int i=0;i<k.length();++i){
        if(s[dem]==k[i]) dem++;
    }
    if(dem==s.length()) {
        cout<<"YES"<<endl;
        cout<<k.length()-dem;
    }
    else cout<<"NO";
    return 0;
}