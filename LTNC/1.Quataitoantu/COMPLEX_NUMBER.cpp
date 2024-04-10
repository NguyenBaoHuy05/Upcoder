#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
struct Sp{
    int a,b; 
};
istream& operator >>(istream& in,Sp &p){
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
Sp operator +(Sp c,Sp d){
    c.a+=d.a;
    c.b+=d.b;
    return c;
}
Sp operator -(Sp c,Sp d){
    c.a-=d.a;
    c.b-=d.b;
    return c;
}
double module(Sp c){
    return sqrt(c.a*c.a+c.b*c.b);
}
int main(){
    Sp *c=new Sp[10000],tong;
    tong.a=0;tong.b=0;
    int i=0;
    while(cin>>c[i]){
        ++i;
    }
    for (int j=0;j<i;j++){
        cout<<"{"<<c[j]<<"}"<<" ";
    }
    cout<<endl;
    for (int j=0;j<i;j++){
        cout<<fixed<<setprecision(2)<<module(c[j])<<" ";
    }
    cout<<endl;
    for (int j=0;j<i;j++){
       tong=tong+c[j];
    }
    cout<<"{"<<tong<<"}";
    return 0;
}