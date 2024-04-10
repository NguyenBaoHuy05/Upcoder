#include<iostream>
using namespace std;
class Hinh{
public:
    virtual int Cv()=0;
};
class Hcn:public Hinh{
    int d,r;
public:
    Hcn(int _d=2,int _r=1){ d=_d;r=_r;}
    Hcn(const Hcn & a){ d=a.d;r=a.r;}
    ~Hcn(){}
    ////
    friend istream& operator >>(istream & in, Hcn &s){
        in>>s.d>>s.r;
        return in;
    }
    /////
    int Cv(){
        return (d+r)*2;
    }
};
class Hv:public Hcn{
    int canh;
public:
    Hv(int _canh=2):Hcn(_canh,_canh){ canh=_canh;}
    Hv(const Hv & a):Hcn(a){ canh=a.canh;}
    ~Hv(){}
    ////
    friend istream& operator >>(istream & in, Hv &s){
        int c;
        cin>>c;
        s=Hv(c);
        return in;
    }
    /////
};

int main(){
    char kt;
    int a,b,n=0;
    Hinh *p[100];
    while(cin>>kt){
        if(kt=='a'){
            cin>>a;
            p[n]=new Hv(a);
        } else {
            cin>>a>>b;
            p[n]=new Hcn(a,b);
        }
        n++;
    }
    for(int i=0;i<n;i++){
        cout<< p[i]-> Cv()<<endl;
    }
    return 0;
}