#include<bits/stdc++.h>
using namespace std;
int n,m,p,q,s,t;
int a[100][100];
int dx[]={-1,1,-1,1};
int dy[]={-1,1,1,-1};
int minn=10000,dem=0;
bool check(int i,int j){
    return i>=1 && j>=1 && i<=n && j<=n && a[i][j]==0;
}
void Try(int x,int y,int k=-1){
    if(x==s && y==t){
        minn=min(minn,dem);
        return;
    }
    for(int i=0;i<4;i++){
        int u=x+dx[i];
        int v=y+dy[i];
        int z=dem;
        int tmp=k;
        if(check(u,v)){
            a[u][v]=1;
            if(i/2!=k){
                dem++;
                k=i/2;
            }
            Try(u,v,k);
            a[u][v]=0;
            if(z!=dem){
                dem--;
                k=tmp;
            }
        }
    }
}
int main(){
    int x,y;
    cin>>n>>m>>p>>q>>s>>t;
    for(int i=0;i<m;i++){
        cin>>x;
        cin>>y;
        a[x][y]=1;
    }
    a[p][q]=1;
    Try(p,q);
    if(minn!=10000) cout<<minn;
    else cout<<-1;
    // cout<<endl;
    // a[p][q]=2;a[s][t]=3;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}