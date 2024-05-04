#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool check(string s,vector<string> ss){
    for(int i=0;i<ss.size();i++){
        if(s==ss[i]) return false;
    }
    return true;
}
int main(){
    string a;
    vector<string> s;
    cin>>a;
    int dem=0,n=a.size();
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i;j--){
            string s1=a.substr(i,j-i+1),s2=s1;
            reverse(s1.begin(),s1.end());
            if(s2==s1) if(check(s2,s)) {dem++;s.push_back(s2);}
        }
    }
    cout<<dem;
    return 0;
}