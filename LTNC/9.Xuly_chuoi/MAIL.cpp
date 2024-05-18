#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,s1="@gmail.com";
    while(cin>>s){
        if(s.find(s1)!=string::npos) cout<<s<<endl;
    }
    return 0;
}