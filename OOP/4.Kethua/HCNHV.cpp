#include<iostream>
using namespace std;
class Hcn{
    int d,r;
public:
    //get-set
    //khoitao
    Hcn(int _d=1,int _r=1){
        d=_d;r=_r;
    }
    Hcn(const Hcn &h){
        d=h.d;r=h.r;
    }
    ~Hcn(){}
    ////
    int Cv(){
        return d*2+r*2;
    }
    ////
    friend istream& operator >>(istream& in,Hcn &a){
        in>>a.d>>a.r;
        return in;
    }
    friend ostream& operator <<(ostream& os,Hcn a){
        os<<a.Cv();
        return os;
    }
};
class Hv:public Hcn{
    int c;
public:
    //get-set
    //khoitao
    Hv(int _c=1):Hcn(_c,_c){
        c=_c;
    }
    Hv(const Hv &h):Hcn(h){
        c=h.c;
    }
    ~Hv(){}
    ////
    // int Cv(){
    //     return c*4;
    // }
    ////
    friend istream& operator >>(istream& in,Hv &a){
        int d;
        in>>d;
        a=Hv(d);
        return in;
    }
    friend ostream& operator <<(ostream& os,Hv a){
        os<<a.Cv();
        return os;
    }
};
int main(){
    Hcn a,e;
    Hv b,f;
    int c=0;
    string kt;
    cin>>kt;
    if(kt=="HCN") {
        while(cin>>a){
            if (a.Cv()>c) {
                c=a.Cv();
                e=a;
            }

        }
        cout<<e;
    }
    else if (kt=="HV"){
        while(cin>>b){
            if (b.Cv()>c) {
                c=b.Cv();
                f=b;
            }

        }
        cout<<f;
    }
    
    return 0;
}