
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100][100];
void matran(int x,int y,int k,int& luu,string s,string& ss,int co=0){

    if(x==n-1 && co==0){
        if(k>luu){
            luu=k;
            ss=s;
        }
        return;
    }
    if(co!=0 && x==n-1){
        if(k==co){
        for(char c:s){
            cout<<c<<" ";
        }
        cout<<endl;}
        return;
    }
    string m;
    m=s+to_string(a[x+1][y]);
        matran(x+1,y,k+a[x+1][y],luu,m,ss,co);
    m=s+to_string(a[x+1][y+1]);
        matran(x+1,y+1,k+a[x+1][y+1],luu,m,ss,co);
}
int main(){
    string luu="",s;
    int max=0,ke;
    vector<string>hh;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin>>a[i][j];
        }
    }
    matran(0,0,a[0][0],max,luu+to_string(a[0][0]),s);
    cout<<max<<endl;
    ke=0;
    luu="";
    matran(0,0,a[0][0],ke,luu+to_string(a[0][0]),s,max);
    return 0;
}
