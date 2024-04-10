#include<iostream>
using namespace std;
class TapSoMoi{
    int x,y,z,t;
    public:
        TapSoMoi(){
            x=0;y=0;z=0;t=0;
        }
        friend istream& operator>>(istream& is,TapSoMoi &p){
            is>>p.x>>p.y>>p.z>>p.t;
            return is;
        }
        friend ostream& operator<<(ostream& os,TapSoMoi p){
            os<<"[TapSoMoi] "<<p.x<<";"<<p.y<<";"<<p.z<<";"<<p.t<<endl;
            return os;
        }
        friend TapSoMoi operator +(TapSoMoi a,TapSoMoi b){
            a.x=a.x+b.x;
            a.y=a.y+b.y;
            a.z=a.z+b.z;
            a.t=a.t+b.t;
            return a;
        }
        bool operator <(TapSoMoi a){
            return (x+y+z+t<a.x+a.y+a.z+a.t);
        }
        TapSoMoi operator =(TapSoMoi a){
            x=a.x;
            y=a.y;
            z=a.z;
            t=a.t;
        }
        TapSoMoi operator ++(){
            ++x;++t;
            return *this;
        }
};
int main(){
    TapSoMoi a,b;
    cin>>a>>b;
    cout<<a;
    cout<<b;
    cout<<(a<b?"true":"false")<<endl;
    cout<<a+b;
    cout<<++a;
    return 0;
}