#include<bits/stdc++.h>
using namespace std;
int n,w,a[100];
int sum=0,maxx=0,dem=0;
vector <int> s,h;
bool b[100];
void Try(int j,int k){
    if(k==0){
        if(sum<=w){
            if(maxx<max(maxx,sum)){
                maxx=max(maxx,sum);
                h=s;
            }
        }
        return;
    }
    for(int i=j;i<n;i++){
        if(b[i]==true){
            b[i]=false;
            sum+=a[i];
            s.push_back(i);
            Try(i+1,k-1);
            sum-=a[i];
            s.pop_back();
            b[i]=true;
        }
    }
}
int main(){
    cin>>n>>w;
    memset(b,true,sizeof(b));
    for(int i=0;i<n;i++){
        cin>>a[i];
    };
    for(int j=1;j<=n;j++){
        Try(0,j);
    }
    cout<<maxx<<endl;
    for(int x:h) cout<<x<<" ";
    return 0;
}