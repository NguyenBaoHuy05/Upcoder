#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    int a=0;
    bool kt=true;
    getline(cin,s1);
    getline(cin,s2);
    while(s1.find(s2,a)!=string::npos){
        cout<<s1.find(s2,a)<<" ";
        a=s1.find(s2,a)+1;
        kt=false;
    }
    if(kt) cout<<-1;
    return 0;
}