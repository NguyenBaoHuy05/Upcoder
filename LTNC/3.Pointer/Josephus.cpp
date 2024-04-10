#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    bool *a=new bool[n+1];
    for (int i=1;i<=n;i++){
        a[i]=true;
    }
    int i=1;
    int l=0;
    int dem=0;
    while(dem<n){
        if(a[i]) ++l;
        if (l==m){
            dem++;
            cout<<i<<" ";
            a[i]=false;
            l=0;
        }
        if(i<n) i++;
        else i=1;
    }
    return 0;
}