#include<iostream>
#include<iomanip>
using namespace std;
class Diem{
    float a[100];
    int n;
    public:
        void setn(int _n){
            n=_n;
        }
        int getn(){
            return n;
        }
        float &operator [](int i){
            return a[i];
        }
        ///
        Diem(int _n=0,float _a[]=new float{0}){
            n=_n;
            for (int i=0;i<n;i++){
                a[i]=_a[i];
            }
        }
        Diem(const Diem &m){
            n=m.n;
            for (int i=0;i<m.n;i++){
                a[i]=m.a[i];
            }
        }
        ~Diem(){}
        //////
        friend istream& operator >>(istream& is,Diem &a){
            a.n=0;
            while(is>>a[a.n]) a.n++;
            return is;
        }
        friend ostream& operator <<(ostream& os,Diem a){
            for(int i=0;i<a.n;i++){
                os<<a.a[i];
            }
            return os;
        }
        float dtb(){
            float tong=0;
            for(int i=0;i<n;i++){
                tong+=a[i];
            }
            return tong/n;
        }
};          
class SinhVien{
    string Hoten,maSV;
    Diem d;
    public:
        void setname(string s){
            Hoten=s;
        }
        string getname(){
            return Hoten;
        }
        void setmasv(string s){
            maSV=s;
        }
        string getmasv(){
            return maSV;
        }
        void setDiem(Diem _d){
            d=_d;
        }
        Diem getDiem(){
            return d;
        }
        /////
        SinhVien(string a="hoten",string b="masv",Diem _d=Diem()){
            Hoten=a;
            maSV=b;
            d=_d;
        }
        SinhVien(const SinhVien &a){
            Hoten=a.Hoten;
            maSV=a.maSV;
            d=a.d;
        }
        ~SinhVien(){}
        //////
        friend istream& operator >>(istream& is,SinhVien &a){
            getline(is,a.Hoten);
            is.ignore();
            getline(is,a.maSV);
            is>>a.d;
            is.clear();
            return is;
        }
        friend ostream& operator <<(ostream& os,SinhVien a){
            os<<a.Hoten<<endl;
            os<<a.maSV<<endl;
            os<<fixed<<setprecision(2)<<a.getDiem().dtb();
            return os;
        }
        bool operator <(SinhVien a){
            return d.dtb()<a.d.dtb();
        }

};


int main(){
    SinhVien a;
    cin>>a;
    cout<<a;
    return 0;
}