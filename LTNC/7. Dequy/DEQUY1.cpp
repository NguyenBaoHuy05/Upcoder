#include<bits/stdc++.h>
using namespace std;
void so(int n,int k,string s=""){
    if(k==0) {
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
    cout<<pow(a*1.0,b*1.0)<<endl;
    so(a,b);
    return 0;
}