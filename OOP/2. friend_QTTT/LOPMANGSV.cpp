#include<iostream>
#include<iomanip>
using namespace std;
class Diem{
    float a[100];
    int n;
    public:
        //get/set
        void setN(int a){
            n=a;
        }
        int getN(){
            return n;
        }
        float &operator [] (int i){
            return a[i];
        }
        //kt-huy
        ~Diem(){}
        Diem(int _n=1 , float _a[]= new float{0} ){
            n=_n;
            for (int i=0;i<n;i++) a[i]=_a[i];
        }
        Diem(const Diem &d){
            n=d.n;
            for (int i=0;i<n;i++) a[i]=d.a[i];

        }
        //nhap-xuat
        friend istream& operator >>(istream& i,Diem &d){
            
            d.n=0;
            while(i>>d.a[d.n]) d.n++;
            return i;
        }
        friend ostream& operator <<(ostream& o,Diem d){
            for (int i=0;i<d.n;i++)  o<<d.a[i]<<" ";
            o<<endl;
            return o;
        }
        //tbc
        float getTB(){
            float tong=0;
            for (int i=0;i<n;i++) tong+=a[i];
            return tong/n;
        }
};
class SinhVien{
    string Hoten,MSinhVien;
    Diem d;
    public:
        //get-set
        void setHoten(string a){
            Hoten=a;
        }
        string getHoten(){
            return Hoten;
        }
        void setMSinhVien(string a){
            MSinhVien=a;
        }
        string getMSinhVien(){
            return MSinhVien;
        }
        void setDiem(Diem a){
            d=a;
        }
        Diem getDiem(){
            return d;
        }
        // Kt-Huy;
        ~SinhVien(){}
        SinhVien(string _a="hoten",string _msSinhVien="mssv",Diem _d=Diem()){
            Hoten=_a;
            MSinhVien=_msSinhVien;
            d=_d;

        }
        SinhVien(const SinhVien &a){
            Hoten=a.Hoten;
            MSinhVien=a.MSinhVien;
            d=a.d;
        }
        //////nhap/xuat
        friend istream& operator>>(istream& i,SinhVien &a){
                getline(i,a.Hoten);
                i>>a.MSinhVien>>a.d;
                return i;
        }
        friend ostream& operator<<(ostream& o,SinhVien a){
                o<<"Ho Ten: "<<a.Hoten<<endl;
                o<<"Ma Sinh Vien: "<<a.MSinhVien<<endl;
                o<<"DTB: "<<fixed<<setprecision(1)<<a.d.getTB();
                return o;
        }
        friend bool operator <(SinhVien a,SinhVien b){
            return a.d.getTB()<b.d.getTB();
        }
};
class MSV{
    
    SinhVien a[100];
    int n;
    public:
        ////get/set
        void setn(int _n){
            n=_n;
        }
        int getn(){
            return n;
        }
        SinhVien &operator[](int i){
            return a[i];
        }
        ////Kt-Huy
        ~MSV(){}
        
        MSV(int _n=1,SinhVien _a[]=new SinhVien{SinhVien()}){
            n=_n;
            for(int i=0;i<n;i++) a[i]=_a[i]; 
        }
        MSV(const MSV &b){
            n=b.n;
            for(int i=0;i<n;i++) a[i]=b.a[i]; 
        }
        ////nhap/xuat
        friend istream& operator>>(istream& in,MSV &p){
            in>>p.n;
            for(int i=0;i<p.n;i++) {
                in.ignore();
                in.clear();
                in>>p.a[i];
                
            }
            return in;
        }
        friend ostream& operator<<(ostream& cout,MSV p){
            
            for(int i=0;i<p.n;i++) cout<<p.a[i]<<" "<<endl;
            return cout;
        }
        ////
        float getTBM(){
            float c=0;
            for (int i=0;i<n;i++) c+=a[i].getDiem().getTB();
            c=c/n;
            return c;
        }
        void max(){
            float c=0;int d;
            for (int i=0;i<n;i++) if(c<a[i].getDiem().getTB()) {
                d=i;c=a[i].getDiem().getTB();            }
            cout<<a[d];
        }

};
int main(){
    MSV a;
    cin>>a;
    a.max();
    return 0;
}