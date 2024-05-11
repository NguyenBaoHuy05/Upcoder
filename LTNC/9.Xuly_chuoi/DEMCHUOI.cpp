#include<iostream>
#include<vector>
#include<sstream>
int gt(int n){
    if(n==1 || n==0) return 1;
    return n*gt(n-1);
}
using namespace std;
int main(){
    string s,a;
    stringstream ss;
    vector<string> luu,all;
    int dem=0;
    getline(cin,s);
    ss<<s;
    while(ss>>a) {
        all.push_back(a);
        bool kt=true;
        for(int i=0;i<luu.size();i++){
            if(luu[i]==a) kt=false;
        }
        if(kt) {dem++;luu.push_back(a);}
    }
    int n[luu.size()]{0};
    for(int i=0;i<all.size();i++){
        for(int j=0;j<luu.size();j++){
            if(all[i]==luu[j]) n[j]++;
        }
    }
    long long tich=1;
    for(int i=0;i<luu.size();i++){
        tich*=gt(n[i]);
    }
    if(luu.size()!=1) cout<<gt(all.size())/tich;
    else cout<<1;
    return 0;
}