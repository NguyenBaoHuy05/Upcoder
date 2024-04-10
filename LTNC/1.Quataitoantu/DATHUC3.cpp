#include<iostream>
using namespace std;
struct Bh{
    int a,b,c;
};
struct Bm{
    int a,b;
};
istream& operator >>(istream& in,Bh &p){
    in>>p.a>>p.b>>p.c;
    return in;
}
istream& operator >>(istream& in,Bm &p){
    in>>p.a>>p.b;
    return in;
}
ostream& operator <<(ostream& out,Bh p){
    out<<p.a<<"x^2+"<<p.b<<"x+"<<p.c;
    return out;
}
ostream& operator <<(ostream& out,Bm p){
    out<<p.a<<"x+"<<p.b;
    return out;
}
long tinhGT(Bh p,int c){
    long a=p.a*(c*c)+p.b*c+p.c;
    return a;
}
Bh operator +(Bh c,Bh d){
    c.a=c.a+d.a;
    c.b=c.b+d.b;
    c.c=c.c+d.c;
    return c;
}
Bh operator * (Bm c,Bm d){
    Bh h;
    h.a=c.a*d.a;
    h.b=c.a*d.b+c.b*d.a;
    h.c=c.b*d.b;
    return h;
}
bool operator ==(Bh c,Bh d){
    if (c.a==d.a and c.b==d.b and c.c==d.c) return true;
    else return false;
}
int main(){
    Bh f1,f2,f5,f6;
    Bm f3,f4;
    cin>>f1>>f2;
    cin>>f3>>f4;
    f6=f3*f4;
    f5=f1+f2;
    int x;
    cin>>x;
    cout<<f1<<endl<<tinhGT(f1,x)<<endl;
    cout<<f2<<endl<<tinhGT(f2,x)<<endl;
    cout<<f5<<endl<<tinhGT(f5,x)<<endl;
    cout<<"("<<f3<<")"<<"*"<<"("<<f4<<")="<<f6<<endl;
    cout<<tinhGT(f6,x)<<endl;
    
    if (f1==f2 and f2==f6 and f1==f6) cout<<"TRUE3"<<endl;//Dễ bị lừa nha

    else if (f1==f6) cout<<"TRUE1"<<endl;
    else if (f2==f6) cout<<"TRUE2"<<endl;
    
    else if (!(f1==f2 and f2==f6 and f1==f6)) cout<<"FALSE";
    return 0;
}