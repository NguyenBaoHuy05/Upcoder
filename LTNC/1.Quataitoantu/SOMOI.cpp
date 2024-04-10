#include<iostream>
using namespace std;
struct Sm{
    int a;
};
istream& operator >>(istream& in,Sm &p){
    in>>p.a;
    return in;
}
ostream& operator <<(ostream& out,Sm p){
    out<<"[SoMoi] "<<p.a<<endl;
    return out;
}
int tcs(int a){
    int b=0;
    while(a){
        b+=a%10;
        a/=10;
    }
    return b;
}
bool operator >(Sm c,Sm d){
    return tcs(c.a)>tcs(d.a);
}
Sm operator +(Sm c,Sm d){
    Sm h;
    h.a=tcs(c.a)+tcs(d.a);
    return h;
}
int main(){
    Sm a,b;
    cin>>a>>b;
    cout<<a<<b;
    if (a>b) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    cout<<a+b;
    return 0;
}