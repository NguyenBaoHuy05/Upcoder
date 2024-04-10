#include<iostream>
using namespace std;
struct Mch{
    int n;
    int m[100];
};
istream& operator>>(istream& in,Mch &p){
    in>>p.n;
    for (int i=0;i<p.n;i++){
        in>>p.m[i];
    }
    return in;
}
ostream& operator<<(ostream& out,Mch p){
    for (int i=0;i<p.n;i++){
        out<<p.m[i]<<" ";
    }
    return out;
}
Mch operator +(Mch a,Mch b){
    Mch h;
    if (max(a.n,b.n)==a.n){
        for (int j=b.n;j<a.n;j++){
            b.m[j]=0;
        }
    }
    else for (int j=a.n;j<b.n;j++){
            a.m[j]=0;
        }
    for (int i=0;i<max(a.n,b.n);i++){
        h.m[i]=a.m[i]+b.m[i];
    }
    h.n=max(a.n,b.n);
    return h;
}
int main(){
    Mch a,b,c;
    cin>>a>>b;
    c=a+b;
    cout<<c;
    return 0;
}