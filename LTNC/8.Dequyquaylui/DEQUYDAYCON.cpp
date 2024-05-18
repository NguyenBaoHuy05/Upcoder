#include<bits/stdc++.h>
using namespace std;
int n,h,sum=0;
int a[100];
bool b[100];
bool kt=false;
void Try(int j,int k){
    if(k==0){
        if(sum==h){
            kt=true;
            for(int i=0;i<n;i++){
                if(b[i]) cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=j;i<n;i++){
        if(!b[i]){
            sum+=a[i];
            b[i]=true;
            Try(i+1,k-1);
            b[i]=false;
            sum-=a[i];
        }
    }
}
int main(){
    cin>>n>>h;
    memset(b,false,sizeof(b));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n;i>=1;i--){
        Try(0,i);
    }
    if(!kt) cout<<-1;
    return 0;
}