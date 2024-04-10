#include<iostream>
#include<cmath>
using namespace std;
struct diem{
    int x,y;
};
istream& operator >>(istream& i,diem &p){
    i>>p.x>>p.y;
    return i;
}
ostream& operator <<(ostream& o,diem p){
    o<<"("<<p.x<<","<<p.y<<")";
    return o;
}
float kc(diem a, diem b){
    float c;
    c=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return c;
}
bool operator ==(diem a,diem b){
    return (a.x==b.x && a.y==b.y);
}
struct Tgiac{
    diem a,b,c;
};
istream& operator >>(istream& i,Tgiac &p){
    i>>p.a>>p.b>>p.c;
    return i;
}
ostream& operator <<(ostream& o,Tgiac p){
    o<<p.a<<p.b<<p.c<<endl;
    return o;
}
float cv(Tgiac a){
    float cv;
    cv=kc(a.a,a.b)+kc(a.b,a.c)+kc(a.c,a.a);
    return cv;
}
float operator +(Tgiac a,Tgiac b){
    return cv(a)+cv(b);
}
bool operator <(Tgiac a,Tgiac b){
    return (cv(a)<cv(b));
}
bool operator ==(Tgiac a,Tgiac b){
    return ((a.a==b.a && a.b==b.b && a.c==b.c) || cv(a)==cv(b));
}
int main(){
    Tgiac a,b;
    cin>>a>>b;
    cout<<a<<b;
    if(a<b) cout<<"TRUE";
    else cout<<"FALSE";
    cout<<endl;
    if(a==b) cout<<"TRUE";
    else cout<<"FALSE";
    return 0;
}