#include<iostream>
#include<algorithm>
using namespace std;
class ps{
    int t,m;
    public:
        ps(){
            t=0;m=1;
        }
        ps(int tu,int mau){
            t=tu;m=mau;
        }
        ps(int tu){
            t=tu;m=1;
        }
        ps(const ps &a){
            t=a.t;m=a.m;
        }
        friend istream& operator>>(istream& in,ps &p){
            in>>p.t>>p.m;
            return in;
        }
        friend ostream& operator<<(ostream& out,ps p){
            out<<p.t<<"/"<<p.m<<endl;
            return out;
        }
        void sett(int tu){
            t=tu;
        }
        int gett(){
            return t;
        }
        void setm(int mau){
            m=mau;
        }
        int getm(){
            return m;
        }
        ps ngd(ps p){
            ps h;
            h.t=p.m;
            h.m=p.t;
            return h;
        }
        ps rg(ps &p){
            ps h;
            int ucln=__gcd(p.t,p.m);
            p.t/=ucln;
            p.m/=ucln;
            h.t=p.t;
            h.m=p.m;
            return h;
        }
        void cong(ps a,ps b){
            a.t=a.t*b.m+a.m*b.t;
            a.m=a.m*b.m;
            rg(a);
            cout<<a;
        }
        void tru(ps a,ps b){
            a.t=a.t*b.m-a.m*b.t;
            a.m=a.m*b.m;
            rg(a);
            cout<<a;
        }
        void nhan(ps a,ps b){
            a.t=a.t*b.t;
            a.m=a.m*b.m;
            rg(a);
            cout<<a;
        }
        void chia(ps a,ps b){
            a.t=a.t*b.m;
            a.m=a.m*b.t;
            rg(a);
            cout<<a;
        }
        ~ps(){

        }

};


int main(){
    ps a;
    cin>>a;
    cout<<a;
    cout<<a.gett()<<endl;
    cout<<a.getm()<<endl;
    cout<<a.ngd(a);
    cout<<a.rg(a);
    a.cong(a.ngd(a),a);
    return 0;
}