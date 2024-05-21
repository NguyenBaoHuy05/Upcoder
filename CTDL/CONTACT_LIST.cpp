#include<bits/stdc++.h>
using namespace std;
int n;
string s;
struct db{
  string sdt;
  int com,lea;
};
istream& operator>>(istream &in,db &a){
    cin>>a.sdt>>a.com>>a.lea;
    cin.ignore();
    return in;
}
ostream& operator<<(ostream &os,db &a){
    cout<<"{"<<a.sdt<<","<<a.com<<","<<a.lea<<"}";
    return os;
}
void timkiem(db a[]){
    for(int i=0;i<n;i++){
        if(a[i].sdt==s) {
            cout<<a[i]<<endl;
            break;
        }
    }
}
void maxs(db a[]){
    int maxx=0,res;
    for(int i=0;i<n;i++){
        if(a[i].com>maxx){
            maxx=a[i].com;
            res=i;
        }
    }    
    cout<<a[res]<<endl;
}
void mins(db a[]){
    int minn=INT_MAX,res;
    for(int i=0;i<n;i++){
        if(a[i].lea<minn){
            minn=a[i].lea;
            res=i;
        }
    }    
    cout<<a[res]<<endl;
}
int main(){
    cin>>n>>s;
    db a[100];
    
    for(int i=0;i<n;i++) cin>>a[i];
    
    timkiem(a);
    maxs(a);
    mins(a);
    return 0;
}