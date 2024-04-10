#include<iostream>
#include<iomanip>
using namespace std;
struct HCN{
    float d,r;
    HCN operator +=(HCN a){
        d+=a.d;
        r+=a.r;
        return *this;
    }
};
istream& operator>>(istream& i,HCN &a){
    i>>a.d>>a.r;
    return i;
}
ostream& operator<<(ostream& o,HCN a){
    o<<"[HCN]"<<a.d<<","<<a.r;
    return o;
}
bool operator>(HCN a,HCN b){
    return (a.d+a.r>b.d+b.r);
}
template<typename T>
T nho(T a[],int n){
    T b=a[0];
    for (int i=1;i<n;i++) if(b>a[i]) b=a[i];
    return b;
}
template<typename T>
T tong(T a[],int n){
    T b=a[0];
    for (int i=1;i<n;i++) b+=a[i];
    return b;
}


int main(){
    char c;
    int i=0;
    cin>>c;
    if(c=='N'){
        int a[100];
        while(cin>>a[i]) i++;
        cout<<nho<int>(a,i)<<endl<<tong<int>(a,i);
    }
    else if(c=='H'){
        HCN a[100],b;
        float c;
        while(cin>>a[i]) i++;
        cout<<nho<HCN>(a,i)<<endl;
        b=tong<HCN>(a,i);
        c=(b.d+b.r)*2;
        cout<<fixed<<setprecision(1)<<c;
    }
    return 0;
}