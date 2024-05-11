#include<bits/stdc++.h>
using namespace std;
string a[100];
int n=0,dem=0,b[100]{0};
vector <string> s;
long long gt(int n){
    if(n==1) return 1;
    return n*gt(n-1);
}
int main(){
    while(cin>>a[n]) n++;
    for(int i=0;i<n;i++){
        bool kt=true;
        for(int z=0;z<s.size();z++){
            if(a[i]==s[z]) kt=false;
        }
        if(kt){
            s.push_back(a[i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int z=0;z<s.size();z++){
            if(a[i]==s[z]) b[z]++;
        }
    }
    long long tich=1;
    for(int z=0;z<s.size();z++){
        tich*=gt(b[z]);
    }    
    cout<<gt(n)/tich;
    return 0;
}