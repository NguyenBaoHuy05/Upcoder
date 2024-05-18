#include<bits/stdc++.h>
using namespace std;
int n,a[100][100];
int dx[]={-1,1,2,2,1,-1,-2,-2};
int dy[]={-2,-2,-1,1,2,2,1,-1};
int dem=0,total=0;
bool check(int i,int j){
    return i>=0 && j>=0 &&i<n && j<n && a[i][j]==0;
}
void Try(int x,int y){
    if(dem==n*n){
        total++;
    }
    for(int i=0;i<8;i++){
        int u=x+dx[i];
        int v=y+dy[i];
        if(check(u,v)){
            dem++;
            a[u][v]=dem;
            Try(u,v);
            a[u][v]=0;
            dem--;
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dem=1;
            a[i][j]=1;
            Try(i,j);
            a[i][j]=0;
        }   
    }
    cout<<total;
    return 0;
}