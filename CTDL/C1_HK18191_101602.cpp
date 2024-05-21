#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,k=-1;
    cin>>n>>x;
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==x) k=i;
    }
    if(k!=-1){
        cout<<"Y\n"<<k;
    }
    else{
        for(int i=0;i<n;i++)
            if(a[i]>x){
                k=i;
                break;
            }
        cout<<"N\n"<<k;
    }
    return 0;
}