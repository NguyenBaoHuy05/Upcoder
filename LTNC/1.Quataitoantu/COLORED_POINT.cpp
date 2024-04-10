#include<iostream>
#include<string>
using namespace std;
struct Cp{
    int x,y;
    string c;
};
istream& operator >>(istream& in,Cp &p){
    in>>p.x>>p.y>>p.c;
    return in;
}
ostream& operator <<(ostream& out,Cp p){
    out<<"("<<p.x<<","<<p.y<<",#"<<p.c<<")";
    return out;
}
bool dem(Cp c){
    return c.c=="5DC3A8";
}
Cp doi(Cp c){
    if(c.x>c.y) c.c="1F00F3";
    return c;
}

int main(){
    int n,z=0;
    cin>>n;
    Cp *a=new Cp[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<n;i++){
        if(dem(a[i])) z++;
    }
    cout<<z<<endl;
    for (int i=0;i<n;i++){
       cout<<doi(a[i]);
    }
    return 0;
}