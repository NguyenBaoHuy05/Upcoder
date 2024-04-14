#include<iostream>
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
int main(){
    int b;
    cin>>b;
    VoiPhun a[100];
    for(int i=0;i<b;i++){
        cin>>a[i];
    }
    for(int i=0;i<b;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}