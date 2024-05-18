#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[100][100];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int dem,maxx=0;
bool check(int i,int j){
    return i>=1 && j>=1 && i<=n && j<=m && a[i][j]=='1';
}
void Try(int,int,int);
void Try1(int x,int y,int k,int z,int p){
    int u=x+dx[z];
    int v=y+dy[z];
    if(check(u,v)){
        dem++;
        u+=dx[p];
        v+=dy[p];
        if(check(u,v)){
            dem++;
            Try(u,v,k);
        }
    }
}
void Try(int x,int y,int k=-1){
    if(k==-1){
        for(int i=0;i<4;i++){
            int u=x+dx[i];
            int v=y+dy[i];
            if(check(u,v)){
                dem++;
                Try(u,v,i);
            }
        }
    }
    if(k==0){
        Try1(x,y,k,1,0);
    }
    if(k==1){
        Try1(x,y,k,2,1);
    }
    if(k==2){
        Try1(x,y,k,3,2);
    }
    if(k==3){
        Try1(x,y,k,0,3);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i][j]=='1'){
                a[i][j]=='0';
                dem=1;
                Try(i,j);
                maxx=max(dem,maxx);
                a[i][j]='1';
            }
        }
    cout<<maxx;
    return 0;
}