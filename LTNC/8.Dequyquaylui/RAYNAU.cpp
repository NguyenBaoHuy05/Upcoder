#include<bits/stdc++.h>
using namespace std;
int m,n;
struct td{
  int x,y;  
};
bool a[100][100];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int dem=0;
vector <td> luu;
td s;
bool check(int i,int j){
    return i>=1 && j>=1 && i<=m && j<=n && a[i][j]==true;
}
void print(){
        cout<<dem<<" ";
        for(int i=0;i<luu.size();i++){
            cout<<"["<<luu[i].x<<","<<luu[i].y<<"]";
            if(i!=luu.size()-1) cout<<", ";
        }
        cout<<endl;
}
void Try(int x,int y){
    if(a[x+1][y]==false && a[x][y+1]==false && a[x-1][y]==false && a[x][y-1]==false){
        if(dem!=0) print();
        return;
    }
    for(int i=0;i<4;i++){
        int u=x+dx[i];
        int v=y+dy[i];
        if(check(u,v)){
            s.x=u;
            s.y=v;
            a[u][v]=false;
            luu.push_back(s);
            dem++;
            Try(u,v);
            luu.pop_back();
            dem--;
        }
    }
    
}
int main(){
    cin>>m>>n;
    int sum=0;
    memset(a,false,sizeof(a));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==true) sum+=1;
        }
    }
    cout<<sum<<endl;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            Try(i,j);
        }
    }
    return 0;
}