#include<bits/stdc++.h>
using namespace std;
struct gt{
  int a,b;  
};
int n,w;
gt a[100];
int sum=0,maxx=0,dem=0,gtm=0;
bool b[100];
string s="";
void Try(int j,int k){
    if(k==0){
        if(sum<=w){
            if(maxx<max(maxx,gtm)){
                maxx=max(maxx,gtm);
                s="";
                for(int i=0;i<n;i++){
                    if(!b[i]) s+="1 ";
                    else s+="0 ";
                }
            }
        }
        return;
    }
    for(int i=j;i<n;i++){
        if(b[i]==true){
            b[i]=false;
            sum+=a[i].a;
            gtm+=a[i].b;
            Try(i+1,k-1);
            sum-=a[i].a;
            gtm-=a[i].b;
            b[i]=true;
        }
    }
}
int main(){
    cin>>n>>w;
    memset(b,true,sizeof(b));
    for(int i=0;i<n;i++){
        cin>>a[i].a>>a[i].b;
    };
    for(int j=1;j<=n;j++){
        Try(0,j);
    }
    cout<<maxx<<endl;
    cout<<s;
    return 0;
}