#include<bits/stdc++.h>
using namespace std;
int n;
char a[100][100];
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
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(check(x,i)){
            a[x][i]='Q';
            Try(x+1);
            a[x][i]='.';
        }
    }
}
int main(){
    cin>>n;
    memset(a,'.',sizeof(a));
    Try(0);
    return 0;
}