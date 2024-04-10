#include<iostream>
using namespace std;
struct Sn{
    int a;
    int n;
};
istream& operator >>(istream& in,Sn &p){
    in>>p.a;
    return in;
}
int Csc(Sn a){
    int b[100],c[100],n=0,z=0;
    while(a.a){
        b[n]=a.a%10;
        n++;
        a.a/=10;
    }
    for (int i=n-1;i>=0;i--){
        c[n-1-i]=b[i];
    }
    for (int i=0;i<n;i++){
        if(i%2==0) z=z*10+c[i];
    }
    return z;
}
ostream& operator <<(ostream& out,Sn p){
    out<<Csc(p)<<endl;
    return out;
}
bool operator <(Sn a,Sn b){
    return (Csc(a)<Csc(b));
}
int tcs(int a){
    int z=0;
    while(a){
        z+=(a%10);
        a/=10;
    }
    return z;
}
int tong(Sn a,int n=0){
    int z,v;
    z=tcs(a.a);
    v=tcs(Csc(a));
    if(n) return (z-v);
    else  return v;
}
int main(){
    Sn a,b;
    int n;
    cin>>a>>b;
    cin>>n;
    cout<<a<<b;
    if(a<b) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    cout<<tong(a,n)<<endl;
    cout<<tong(b,n);
    return 0;
}