#include<iostream>
using namespace std;
struct HCN{
    int a,b;
};
istream& operator >>(istream& in,HCN &p){
    in>>p.a>>p.b;
    return in;
}
ostream& operator <<(ostream& out,HCN p){
    out<<"[HCN] "<<p.a<<","<<p.b<<endl;
    return out;
}
double cv(HCN a){
    double b;
    b=(a.a+a.b)*2;
    return b;
}
bool operator <(HCN c, HCN d){
    return cv(c)<cv(d);
}
double operator + (HCN c,HCN d){
    return cv(c)+cv(d);
}
int main(){
    HCN a,b;
    cin>>a>>b;
    cout<<a<<b;
    if (a<b) cout<<"true";
    else cout<<"false";
    return 0;
}