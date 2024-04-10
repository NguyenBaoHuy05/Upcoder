#include<iostream>
using namespace std;
class khach{
    string ten,kh;
    int tg,sm;
    int gia;
public:
    void setten(string a){ten=a;}
    string getten(){return ten;}
    void settg(int a){tg=a;}
    int gettg(){return tg;}
    void setkh(string a){kh=a;}
    string getkh(){return kh;}
    void setgia(int a){gia=a;}
    int getgia(){return gia;}
    int getsm(){return sm;}
///
    khach(string _ten="ten",int _tg=1,int _sm=1, string _kh="", int g=0){
        ten=_ten;tg=_tg;sm=_sm;kh=_kh;gia=g;
    }
    khach(const khach & a){
        ten=a.ten;tg=a.tg;sm=a.sm;gia=a.gia;
    }
    ~khach(){}
    friend ostream& operator<<(ostream& os,khach &a){
        os<<"Loai khach: "<<a.getkh()<<endl;
        os<<"Ho Ten: "<<a.getten()<<endl;
        os<<"Thoi gian su dung: "<<a.gettg()<<endl;
        os<<"So may: "<<a.getsm()<<endl;
        os<<"So tien phai tra: "<<a.Tien()<<endl<<endl;
    }
    virtual int Tien()=0;
};
class Vip:public khach{
public:
    Vip(string _ten="ten",int _tg=1,int _sm=1,string _kh="",int g=0):khach(_ten,_tg,_sm,_kh,g){}
    /////
    int Tien(){
        if(gettg()<4) return getgia()*gettg();
        else return getgia()*4;
    }
};
class Tx:public khach{
    int hs;
public:
    void seths(int a){hs=a;}
    Tx(string _ten="ten",int _tg=1,int _sm=1,string _kh="",int g=0):khach(_ten,_tg,_sm,_kh,g){}
    int Tien(){       
        return gettg()*getgia()-gettg()*hs;
    }
};
class Ktx:public khach{
    int hs;
public:
    Ktx(string _ten="ten",int _tg=1,int _sm=1,string _kh="",int g=0):khach(_ten,_tg,_sm,_kh,g){}
    void seths(int a){hs=a;}
    int Tien(){
        return gettg()*getgia()+hs;
    }
};
int main(){
    string ten;
    int tg,sm;
    int d,e,f,h,hs;
    string a;
    cin>>d>>e>>f>>h;
    khach *p[100];
    for(int i=0;i<d;i++){
        cin.ignore();
        cin>>a;
        cin.ignore();
        getline(cin,ten);
        cin>>tg>>sm;
        if(a=="VIP"){
            p[i]=new Vip(ten,tg,sm,a,f);
        }
        else if(a=="TX"){
            Tx *t=new Tx(ten,tg,sm,a,e);
            cin>>hs;
            t->seths(hs);
            p[i]=t;
            
           
        }
        else if(a=="KTX"){
            Ktx *t=new Ktx(ten,tg,sm,a,e);
            cin>>hs;
            t->seths(hs*h);
            p[i]=t;
        }
    }
    for(int i=0;i<d;i++){
        cout<<i+1<<". "<<*p[i];
        delete p[i];
    } 
    return 0;
}