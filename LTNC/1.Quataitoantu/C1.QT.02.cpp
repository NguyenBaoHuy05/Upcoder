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
            
             out<<p.a<<"+"<<p.b<<"*"<<"i";
        }
        else if(p.a and p.b<0){
            
             out<<p.a<<p.b<<"*"<<"i";
        }
        else if(!p.a and p.b<0){
            
             out<<"-"<<p.b<<"*"<<"i";
        }
        else if (!p.a and p.b>0){
            
             out<<p.b<<"*"<<"i";
        }
    }
    return out;
}

Sp operator +(Sp c,Sp d){
    Sp e;
    e.a=c.a+d.a;
    e.b=c.b+d.b;
    return e;
}
Sp operator -(Sp c,Sp d){
    Sp e;
    e.a=c.a-d.a;
    e.b=c.b-d.b;
    return e;
}
Sp operator *(Sp c,Sp d){
    Sp e;
    e.a=c.a*d.a - c.b*d.b;
    e.b=c.a*d.b+c.b*d.a;
    return e;
}
Sp operator <(Sp c,Sp d){
    int e=(c.a-d.a)*100+(c.b-d.b);
    if (e>0) return d;
    else return c;
}
Sp operator >(Sp c,Sp d){
    int e=(c.a-d.a)*100+(c.b-d.b);
    if (e>0) return c;
    else return d;
}
int main(){
    int n;
    cin>>n;
    Sp a[n],tong,tich,max,min;
    tong.a=0;tong.b=0;
    tich.a=1;tich.b=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        tong=tong+a[i];
        tich=tich*a[i];
    }
    min=a[0];max=a[0];
    for (int i=1;i<n;i++){
        min=min<a[i];
        max=max>a[i];
    }
    cout<<max<<endl;
    cout<<tong<<endl;
    cout<<tich<<endl;
    cout<<max-min;
    return 0;
}