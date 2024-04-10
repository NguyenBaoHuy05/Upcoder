#include<iostream>
using namespace std;
struct BacNhat{
    int a,b;
};
istream& operator>>(istream& in,BacNhat &p){
    in>>p.a>>p.b;
    return in;
}
ostream& operator <<(ostream& out,BacNhat p){
    out<<p.a<<"x+"<<p.b;
    return out;
}
int tinh(BacNhat a,int x){
    int d=a.a*x+a.b;
    return d;
}
BacNhat operator +(BacNhat c,BacNhat d){
    BacNhat h;
    h.a=c.a+d.a;
    h.b=c.b+d.b;
    return h;
}
bool operator ==(BacNhat c,BacNhat d){
    return c.a+c.b==d.a+d.b;
}
int main(){
    BacNhat a,b;
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