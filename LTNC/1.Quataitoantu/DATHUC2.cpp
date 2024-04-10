#include<iostream>
using namespace std;
struct Bnhat{
    int a,b;
};
istream& operator>>(istream& in,Bnhat &p){
    in>>p.a>>p.b;
    return in;
}
ostream& operator <<(ostream& out,Bnhat p){
    out<<p.a<<"x+"<<p.b;
    return out;
}
int tinh(Bnhat a,int x){
    int d=a.a*x+a.b;
    return d;
}
Bnhat operator +(Bnhat c,Bnhat d){
    Bnhat h;
    h.a=c.a+d.a;
    h.b=c.b+d.b;
    return h;
}
bool operator ==(Bnhat c,Bnhat d){
    return c.a+c.b==d.a+d.b;
}
int main(){
    Bnhat a,b;
    cin>>a>>b;
    int c;
    cin>>c;
    cout<<a<<endl<<b<<endl;
    cout<<a<<"+"<<b<<"="<<a+b<<endl;
    cout<<tinh(a,c)<<endl;
    cout<<tinh(b,c)<<endl;
    if (a==b) cout<<"TRUE";
    else cout<<"FALSE";
    return 0;
}