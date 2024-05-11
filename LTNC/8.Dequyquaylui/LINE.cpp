#include<bits/stdc++.h>
using namespace std;
int n,sy,sx,dy,dx;
bool a[100][100],kt=false;
int ddx[]={0,1,-1,0};
int ddy[]={1,0,0,-1};
bool check(int i,int j){
    return i>=1 && i<=n && j>=0 && j<=n && a[i][j]==false;
}
void Try(int x,int y){
    if(x!=dy && y!=dx && a[x][y+1]==true && a[x+1][y]==true && a[x-1][y]==true && a[x][y-1]==true){
        return;
    }
    if(x==dy && y==dx){
        kt=true;
        return;
    }
    if(!kt){
        for(int i=0;i<4;i++){
            int u=x+ddx[i];
            int v=y+ddy[i];
            if(check(u,v)){
                a[u][v]=true;
                Try(u,v);
                a[u][v]=false;
            }
        }
    }
}
int main(){
    ifstream cin("LINE.inp");
    ofstream cout("LINE.out");
    cin>>n>>sy>>sx>>dy>>dx;
    memset(a,true,sizeof(a));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    Try(sy,sx);
    if(kt) cout<<"YES";
    else cout<<"NO";
    cin.close();
    cout.close();
    return 0;
}