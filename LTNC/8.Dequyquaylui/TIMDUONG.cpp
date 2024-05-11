#include<bits/stdc++.h>
using namespace std;
struct kn{
  int x,y;  
};
kn a[100];
int n,m,kx,ky;
int minn=10000,dem=1;
bool kt(int j){
    for(int i=j;i<n;i++){
        if(a[j].y==a[i].x) return true;
    }
    return false;
}
void Try(int j){
    if(a[j].y==ky){
        minn=min(minn,dem);
        return;
    }
    if(kt(j)==false){
        return;
    }
    for(int i=j;i<n;i++){
        if(kt(i)){
                dem++;
                Try(i+1);
                dem--;
        }
    }
}
int main(){
    cin>>m>>n>>kx>>ky;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    for(int i=0;i<n;i++){
        if(a[i].x==kx) Try(i);
    }
    cout<<minn;
    return 0;
}