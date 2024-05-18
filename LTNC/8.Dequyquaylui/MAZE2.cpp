#include<bits/stdc++.h>
using namespace std;
int n;
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
bool a[100][100];
bool kt=false;
string s="";
bool check(int i,int j){
    return i>=1 && j>=1 && i<=n && j<=n && a[i][j]==true;
}
void Try(int x,int y){
    if(x==n && y==n){
        cout<<s<<endl;
        kt=true;
        return;
    }
    if(a[x+1][y]==false && a[x][y+1]==false && a[x][y-1]==false && a[x-1][y]==false){
        return ;
    }
    for(int i=0;i<4;i++){
        int u=x+dx[i];
        int v=y+dy[i];
        if(check(u,v)){
            a[u][v]=false;
            if(i==0) s+='X';
            else if(i==1) s+='P';
            else if(i==2) s+='T';
            else s+='L';
            Try(u,v);
            s.erase(s.size()-1,1);
            a[u][v]=true;
        }
    }
}
int main(){
    cin>>n;
    memset(a,false,sizeof(a));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    a[1][1]=false;
    Try(1,1);
    if(!kt) cout<<-1;
    return 0;
}