#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int a[200];
    bool kt=true;
    memset(a,0,sizeof(a));
    for(int i=0;i<s1.size();i++){
        a[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++){
        a[s2[i]]--;
    }
    for(int i=0;i<200;i++){
        if(a[i]!=0) {kt=false;break;}
    }
    if(kt) cout<<"True";
    else cout<<"False";
    return 0;
}