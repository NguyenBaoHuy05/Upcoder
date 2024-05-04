#include<bits/stdc++.h>
using namespace std;
void so(int n,int k,string s=""){
    if(k==0) {
        int a[10]{0};
        for(int i=0;i<s.size();++i){
            a[s[i]-'0']++;
        }
        for(int i=0;i<10;++i){
            if(a[i]>1) return;
        }
        cout<<s<<endl;
        return;
    }
    for(int i=1;i<=n;++i){
        string ss=to_string(i);
        so(n,k-1,s+ss);
    }
}
int main(){
    int a,b;
    cin>>a>>b;
    so(b,a);
    return 0;
}