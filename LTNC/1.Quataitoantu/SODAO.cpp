#include <iostream>
using namespace std;
struct SoDao{
    int a;
};
istream& operator >>(istream& in, SoDao &p){
    in>>p.a;
    return in;
}
ostream& operator <<(ostream& out, SoDao p){
    out<<"[SoDao] "<<p.a<<endl;
    return out;
}

int dn(SoDao c){
    int a=0;
    while(c.a){
        a=a*10+(c.a%10);
        c.a/=10;
    }
    return a;
}

bool operator > (SoDao c,SoDao d){
    return dn(c)>dn(d);
}
int operator +(SoDao c,SoDao d){
    c.a=dn(c)+dn(d);
    return c.a;
}
int main(){
    SoDao a,b;
    cin>>a>>b;
    cout<<a<<b;
    if (a>b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    cout<<a+b;
    return 0;
}