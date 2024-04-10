#include<bits/stdc++.h>
using namespace std;
struct Sp{
    int a,b;
};
istream& operator>>(istream& in,Sp &p){
    in>>p.a>>p.b;
    return in;
}
ostream& operator<<(ostream& out,Sp p){
    if (!p.b) out<<p.a;
    else {
        if (p.a and p.b>0){
            if(abs(p.b)==1) out<<p.a<<"+"<<"i";
            else out<<p.a<<"+"<<p.b<<"i";
        }
        else if(p.a and p.b<0){
            if(abs(p.b)==1) out<<p.a<<"-"<<"i";
            else out<<p.a<<p.b<<"i";
        }
        else if(!p.a and p.b<0){
            if(abs(p.b)==1) out<<"-"<<"i";
            else out<<p.b<<"i";
        }
        else if (!p.a and p.b>0){
            if(abs(p.b)==1) out<<"i";
            else out<<p.b<<"i";
        }
    }
    return out;
}
struct Ps{
    int t,m;
};
istream& operator >>(istream& in,Ps &p){
    in>>p.t>>p.m;
    return in;
}
ostream& operator <<(ostream& out,Ps p){
    if (p.t) out<<p.t<<"/"<<p.m<<endl;
    else out<<0<<endl;
    return out;
}
void xlPs(Ps &a){
    int ucln=__gcd(a.t,a.m);
    a.t/=ucln;
    a.m/=ucln;
    if (a.m<0) {
        a.t=-a.t;
        a.m=-a.m;
    }
    if (!a.t){
        a.m=0;
    }
}
Sp operator +(Sp c,Sp d){
    Sp e;
    e.a=c.a+d.a;
    e.b=c.b+d.b;
    return e;
}
int main(){
    Sp a,h;
    cin>>a;
    cout<<a<<endl;
    char kt;
    cin>>kt;
    if (kt=='z'){
        cin>>h;
        cout<<h<<endl;
        cout<<h+a;
    }
    else if(kt=='i'){
        int k;
        cin>>k;
        cout<<k<<endl;
        h.a=k;h.b=0;
        cout<<h+a;
    }
    else if (kt=='p'){
        Ps k;
        cin>>k;
        xlPs(k);
        cout<<k;
        h.a=k.t;
        h.b=k.m;
        cout<<h+a;
    }
    return 0;
}