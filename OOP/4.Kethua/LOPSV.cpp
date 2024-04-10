#include<iostream>
#include<iomanip>
using namespace std;
class Human{
    string ten;
    int nam;
    string que;
public:
    //get-set
    void setname(string _a){ten=_a; }
    string getname(){return ten;}
    void setnam(int _a){nam=_a;}
    int getnam(){return  nam;}
    void setque(string _a){que=_a;}
    string getque(){return que;}
    ///khoitao
    ~Human(){}
    Human(string a="hoten",int b=1900,string c="quequan"){
        ten=a; nam=b; que=c;
    }
    Human(const Human &a){
        ten=a.ten; nam=a.nam; que=a.que;
    }
    //////
    friend istream& operator >>(istream& in,Human &a){
        getline(in,a.ten);
        in>>a.nam;
        in.ignore();
        getline(in,a.que);
        return in;
    }
    friend ostream& operator <<(ostream& os,Human a){
        os<<"Ho Ten: "<<a.ten<<endl;
        os<<"Nam Sinh: "<<a.nam<<endl;
        os<<"Que quan: "<<a.que<<endl;
        return os;
    }
};
class Sv:public Human{
    string khoa;
    int n;
    float a[100];
public:
    ///getset
    void setkhoa(string _a)     {khoa=_a;}
    string getkhoa()            {return khoa;}
    void setn(int _n)           {n=_n; }
    int getn()                  {return n;}
    float &operator [](int i)   {return a[i];}
    /////khoitao
    ~Sv(){}
    Sv(string _ten="hoten",int _nam=1900,string _que="quequan", string m="khoa" ,float b[]=new float {1},int _n=1):Human(_ten,_nam,_que){
        khoa=m;
        n=_n;
        for(int i=0;i<n;i++){
            a[i]=b[i];
        }
    }
    Sv(const Sv &b):Human(b){
        khoa=b.khoa;
        n=b.n;
        for(int i=0;i<b.n;i++){
            a[i]=b.a[i];
        }
    }
    /////dtb
    float dtb(){
        float b=0;
        for(int i=0;i<n;i++){
            b+=a[i];
        }
        return b/n;
    }
    /////nhap/xuat
    friend istream& operator >>(istream& in,Sv &a){
        string ten,que,khoa;
        int nam,n;
        float diem[100];

        getline(in,ten);
        in>>nam;
        in.ignore();
        getline(in,que);

        n=0;
        getline(in,khoa);
        while(in>>diem[n]) n++;
        a = Sv(ten,nam,que,khoa,diem,n);
        return in;
    }
    friend ostream& operator <<(ostream& os,Sv a){
        os<<"Ho Ten: "<<a.getname()<<endl;
        os<<"Nam Sinh: "<<a.getnam()<<endl;
        os<<"Que quan: "<<a.getque()<<endl;
        os<<"Khoa: "<<a.khoa<<endl;
        os<<"Diem cac mon: ";
        for(int i=0;i<a.n;i++){
            os<<a.a[i]<<" ";
        }
        os<<endl;
        os<<"Diem trung binh: "<<fixed<<setprecision(2)<<a.dtb();
    }
};
int main(){
    Sv a;
    cin>>a;
    cout<<a;
    return 0;
}