#include<iostream>
#include<cmath>
using namespace std;
struct Dathuc{
    int n;
    int m[100];
};
istream& operator >>(istream& in,Dathuc &p){
    in>>p.n;
    for (int i=p.n;i>=0;i--){
        in>>p.m[i];
    }
    return in;
}
ostream& operator <<(ostream& out,Dathuc p){
    int z=0;
    for (int i=p.n;i>=0;i--){
        if (p.m[i]) z++;
    }
    int k=z;
    if(z==0) out<<0;
    else {
        for (int i=p.n;i>=0;i--){
        if (p.m[i]){
            if (abs(p.m[i])!=1 and p.m[i]<0) out<<"-"<<abs(p.m[i]);
            else if (abs(p.m[i])==1 and p.m[i]<0 and i) out<<"-";
            else if (abs(p.m[i])==1 and p.m[i]<0 and !i) out<<p.m[i];
            else if (abs(p.m[i])!=1 and z!=k and p.m[i]>0 and k!=1) out<<"+"<<p.m[i];
            else if (abs(p.m[i])!=1 and z==k and p.m[i]>0 ) out<<p.m[i];
            else if (abs(p.m[i])==1  and p.m[i]>0 and k==1 and i<1) out<<p.m[i];
            else if (abs(p.m[i])==1 and z==k and p.m[i]>0 and k!=1) out<<"";
            else if (abs(p.m[i])==1 and z!=k and p.m[i]>0 and i and k!=1) out<<"+";
            else if (abs(p.m[i])==1 and !i and p.m[i]>0 and k!=1 ) out<<"+"<<p.m[i];
        }
        if (z>0 and p.m[i]) {
            if (i==1) out<<"x";
            else if(i==0) out<<"";
            else if(i>1) out<<"x^"<<i;
            z--;
        }
    }
    }
    out<<endl;
    return out;
}
void daoham(Dathuc &p){
    for (int i=1;i<=p.n;i++){
        p.m[i-1]=p.m[i]*i;
    }
    --p.n;
}

int main(){
    Dathuc a;
    cin>>a;
    cout<<a;
    daoham(a);cout<<a;
    daoham(a);cout<<a;
    return 0;
}