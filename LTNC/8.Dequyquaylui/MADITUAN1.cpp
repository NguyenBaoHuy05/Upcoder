#include<bits/stdc++.h>
using namespace std;
int n;
bool a[100][100] ;
int dx[]={-2,-1,-2,-1,+1,+2,+2,+1};
int dy[]={-1,-1,1,2,-2,-1,+1,+2};
int dem=0;
bool check(int i,int j){
    return i>=0 && j>=0 && i<n && j<n;
}
void Try(int x,int y,int maxd){
    if(!check(x,y)){
        //dem++;
        return;
    }
    for(int i=0;i<8;i++){
        int u=x+dx[i];
        int v=y+dy[i];
        if(check(u,v) && a[u][v]==false){
            dem++;
            a[u][v]=true;
            Try(u,v,maxd+1);
            a[u][v]=false;
        }
    }
}
int main(){
    long sum=0;
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            memset(a, false, sizeof(a));
            a[i][j]=true;
            dem=0;
            Try(i,j,0);
            sum+=dem;
        }
    }
    cout<<sum;
    return 0;
}