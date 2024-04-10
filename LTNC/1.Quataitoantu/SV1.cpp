#include<iostream>
using namespace std;
struct Sv{
    string s;
    float a,b,c;
};
istream& operator >>(istream& i,Sv &p){
    getline(i,p.s);
    i>>p.a>>p.b>>p.c;
    return i;
}
ostream& operator <<(ostream& o,Sv p){
    o<<p.s;
    return o;
}
float dtb(Sv a){
    return (a.a+a.b+a.c)/3;
}
bool operator <(Sv a,Sv b){
    return (dtb(a)<dtb(b));
}
int main(){
    Sv a[100],z;
    int i=0,k;

    while(cin>>a[i]) {
        i++;
        cin.ignore();
    }
    z=a[0];
    for (int j=1;j<i;j++){
        if(z<a[j]) {
            z=a[j];
        }
    }
    cout<<z;
    return 0;
}