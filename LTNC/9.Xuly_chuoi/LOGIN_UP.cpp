#include<iostream>
#include<vector>
using namespace std;

bool kt(string luu, string s){
    int dem=0;
    for(int i=0;i<s.length();i++){
        if(luu[dem]==s[i]) dem++;
    }
    if(dem==luu.length()) return true;
    return false;
}
int main(){
    string s,luu="upcoder";
    getline(cin,s);
    if(kt(luu,s)) cout<<"YES";
    else cout<<"NO";
    return 0;
}