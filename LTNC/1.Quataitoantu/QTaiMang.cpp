#include<iostream>
using namespace std;
struct phanso{
    int n;
    int m[100];
    int operator [] (int b){
    return m[b];
}

};

istream& operator >> (istream& in,phanso &p){
    in>>p.n;
    for (int i=0;i<p.n;i++){
        in>>p.m[i];
    }
    return in;
}
ostream& operator << (ostream& out, phanso p){
    out<<p.n;
    for (int i=0;i<p.n;i++){
        out<<p.m[i];
    }
    return out;
}
phanso operator + (phanso a, phanso b){
    phanso c;
    for (int i=0;i<100;i++){
        c.m[i]=a.m[i]+b.m[i];
    }
    return c;
}
bool operator ==(phanso a,phanso b){
    bool c=a.n==b.n;
    if (!c) return false;
    for (int i=0;i<a.n;i++){
        if (a.m[i]!=b.m[i]) return false;
    }
    return true;
}
bool operator !=(phanso a, phanso b){
    bool c=a==b;
    return !c;
}

int main(){
    phanso a,b;
    cin>>a>>b;
    if (a==b) cout<<"yes";
    else cout<<"no";
    cout<<a[2];
    return 0;
}