#include<bits/stdc++.h>
using namespace std;
int cata(int n){
    if(n==0 || n==1) return 1;
    int res=0;
    for(int i=0;i<n;i++){
        res+=cata(i)*cata(n-1-i);
    }
    return res;
}
int main(){
    int a;
    while(cin>>a) cout<<cata(a)<<endl;
    return 0;
}