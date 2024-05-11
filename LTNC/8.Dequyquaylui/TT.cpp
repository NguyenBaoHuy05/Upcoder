#include<bits/stdc++.h>
using namespace std;
int n,a[20];
int sum=0,all=0,dem=0;
vector <string> s;
bool b[20];
void Try(int j,int k){
    if(k==0){
        if(2*sum==all){
            dem++;
            string k="";
            for(int i=0;i<n;i++){
                if(b[i]) k+="A ";
                else k+="B ";
            }
            s.push_back(k);
        }
        return;
    }
    for(int i=j;i<n;i++){
        if(b[i]==true){
            b[i]=false;
            sum+=a[i];
            Try(i+1,k-1);
            sum-=a[i];
            b[i]=true;
        }
    }
}
int main(){
    cin>>n;
    memset(b,true,sizeof(b));
    for(int i=0;i<n;i++){
        cin>>a[i];
        all+=a[i];
    };
    for(int j=1;j<n;j++){
        Try(0,j);
    }
    if(dem==0) cout<<"khong chia duoc";
    else{
        cout<<dem<<endl;
        sort(s.begin(),s.end());
        for(string c:s){
            cout<<c<<endl;
        }
    }
    return 0;
}