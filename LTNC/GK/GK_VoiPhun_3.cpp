#include<iostream>
#include<math.h>
#include<vector>
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
    return sqrt((a.o.x-b.o.x)*(a.o.x-b.o.x)+(a.o.y-b.o.y)*(a.o.y-b.o.y));
}
bool operator &(VoiPhun a,VoiPhun b){
    return ((a-b)-a.r-b.r<0);
}
double trung(VoiPhun a,VoiPhun b){
    double d=a-b;
    double d1=(a.r*a.r-b.r*b.r+d*d)/(2*d);
    double d2=(-a.r*a.r+b.r*b.r+d*d)/(2*d);
    double an=a.r * a.r * acos(d1/a.r)-d1*sqrt(a.r*a.r-d1*d1)
    +b.r * b.r * acos(d2/b.r)-d2*sqrt(b.r*b.r-d2*d2);
}

int main(){
    VoiPhun a,b;
    cin>>a>>b;
    if(a&b) cout<<"A chong lap B";
    else "A khong chong lap B";
    cout<<endl;
    int c;double d=0;
    cin>>c;
    vector<VoiPhun> e;
    for(int i=0;i<c;i++){
        cin>>a;
        e.push_back(a);
        d+=dt(a);
    }
    return 0;
}