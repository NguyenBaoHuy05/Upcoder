#include<iostream>
#include<math.h>
const double PI = 3.14159;
using namespace std;
struct ToaDo {
     int x,y;
};
istream& operator>>(istream& in,ToaDo &x){
    in>>x.x>>x.y;
    return in;
}
struct VoiPhun {
    ToaDo o;
    int r;
};
istream& operator>>(istream& in,VoiPhun &x){
    in>>x.o>>x.r;
    return in;
}
ostream& operator<<(ostream& os,VoiPhun x){
    os<<"(x"<<((x.o.x<0)?'+':'-')<<abs(x.o.x)<<")^2+(y"<<((x.o.y<0)?'+':'-')<<abs(x.o.y)<<")^2="<<x.r*x.r;
    return os;
}
double dt(VoiPhun a){
    return a.r*a.r*PI;
}
double operator +(VoiPhun a,VoiPhun b){
    return round((dt(a)+dt(b)) * 1000.0F) / 1000.0F;
}
double operator -(VoiPhun a,VoiPhun b){
    return round((sqrt((a.o.x-b.o.x)*(a.o.x-b.o.x)+(a.o.y-b.o.y)*(a.o.y-b.o.y))) * 1000.0F) / 1000.0F;
}
bool operator ==(VoiPhun a,VoiPhun b){
    return a.o.x==b.o.x && a.o.y==b.o.y && a.r==b.r;
}
bool operator <(VoiPhun a,VoiPhun b){
    return a.r<b.r;
}
bool operator >(VoiPhun a,VoiPhun b){
    return a.r>b.r;
}
bool operator &(VoiPhun a,VoiPhun b){
    return !((a-b)<0);
}

int main(){
    VoiPhun a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    if(a==b) cout<<"A trung voi B";
    else cout<<"A khong trung voi B";
    cout<<endl;
    if(a<b) cout<<"A nho hon B";
    else cout<<"A khong nho hon B";
    cout<<endl;
    if(a>b) cout<<"A lon hon B";
    else cout<<"A khong lon hon B";
    return 0;
}