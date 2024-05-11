#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[100][100];
int x,y,dem=0;
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
bool check(int i,int j){
    return i>=1 && i<=n && j>=1 && j<=m && a[i][j]==false;
}
void Try(int i,int j){
    if(a[i][j+1]==false && a[i+1][j]==false && a[i-1][j]==false && a[i][j-1]==false){
        return;
    }
    for(int x=0;x<4;x++){
        int u=i+dx[x];
        int v=j+dy[x];
        if(check(u,v)){
            a[u][v]=true;
            dem++;
            Try(u,v);
        }
    }
}
int main(){
    cin>>n>>m>>x>>y;
    memset(a, true, sizeof(a));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    a[x][y]=true;
    Try(x,y);

    cout<<dem+1;
    return 0;
}