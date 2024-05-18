#include<bits/stdc++.h>
using namespace std;
int n;
char a[100][100];
int b[100][100];
int sum=0,maxx=0;
bool check(int x,int y){
    for(int i=0;i<n;i++){
        if(a[i][y]=='Q') return false;
    }
    for(int i=x,j=y;i>=0 && j>=0;i--,j--){
        if(a[i][j]=='Q') return false;
    }
    for(int i=x,j=y;j<n && i>=0;j++,i--){
        if(a[i][j]=='Q') return false;
    }
    return true;
}
void Try(int x){
    if(x==n){
        maxx=max(maxx,sum);
        return;
    }
    for(int i=0;i<n;i++){
        if(check(x,i)){
            a[x][i]='Q';
            sum+=b[x][i];
            Try(x+1);
            sum-=b[x][i];
            a[x][i]='.';
        }
    }
}
int main(){
    n=8;
    memset(a,'.',sizeof(a));
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            cin>>b[i][j];
    Try(0);
    cout<<maxx;
    return 0;
}