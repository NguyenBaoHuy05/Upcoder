#include<iostream>
#include<algorithm>
using namespace std;
class Ps{
    int t,m;
public:
    ///getset
    void sett(int a){t=a;}
    int gett(){return t;}
    void setm(int a){m=a;}
    int getm(){return m;}
    ////khoitao
    Ps(){
        t=0;m=1;
    }
    Ps(int _t,int _m){
        t=_t;
        m=_m;
    }
    Ps(const Ps &a){
        t=a.t;
        m=a.m;
    }
    ///lay t,m
    int tu(){return t;}
    int mau(){return m;}
    ////nhap/xuat
    friend istream& operator >>(istream& in, Ps &a){
        in>>a.t>>a.m;
        return in;
    }
    friend ostream& operator <<(ostream& os, Ps a){
        os<<a.t<<"/"<<a.m;
        return os;
    }
    ////+
    Ps operator +(Ps a){
        t=t*a.m+m*a.t;
        m=t*m;
        return *this;
    }
};
class Hs:public Ps{
    int nguyen;
public:
    void setng(int a){nguyen=a;}
    int getng(){return nguyen;}
    ////khoitao
    Hs(){
        nguyen=0;
    }
    Hs(int _nguyen,int _t,int _m):Ps(_t,_m){
        nguyen=_nguyen;
    }
    Hs(const Hs &a):Ps(a){
        nguyen=a.nguyen;
    }
    ////nhap/xuat
    friend istream& operator >>(istream& in, Hs &a){
        int x,y,z;
        in>>x>>y>>z;
        if(x>0) a= Hs(x,y,z);
        else a=Hs(x,y*(-1),z);
        return in;
    }
    friend ostream& operator <<(ostream& os, Hs a){
        a=a.rg();
        os<<a.nguyen<<" "<<a.tu()<<"/"<<a.mau();
        return os;
    }
    ////+
    Hs operator +(Hs a){
        nguyen+=a.nguyen;
        return Hs(nguyen,gett()*a.getm()+getm()*a.gett(),getm()*a.getm());
    }
    Hs rg(){
        int ucln=__gcd(abs(gett()),abs(getm()));
        return Hs(nguyen,gett()/ucln,getm()/ucln);
    }
};
int main(){
    Hs a,b;
    cin>>a>>b;
    cout<<a+b;
    return 0;
}