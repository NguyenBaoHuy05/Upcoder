#include<iostream>
#include<algorithm>
using namespace std;
struct Ps{
    int t, m;
};
istream& operator>>(istream& in,Ps &p){
    in>>p.t>>p.m;
    return in;
}
ostream& operator<<(ostream& out,Ps p){
    out<<p.t<<"/"<<p.m;
    return out;
}
Ps rg(Ps a){
    int ucln=__gcd(a.t,a.m);
    a.t/=ucln;
    a.m/=ucln;
    return a;
}
bool operator >(Ps a,Ps b){
    return ((a.t*b.m-a.m*b.t)>0);
}
void swap(Ps &a,Ps &b){
    int l=a.t;
    a.t=b.t;
    b.t=l;
    int k=a.m;
    a.m=b.m;
    b.m=k;
}
int main(){
    int n;
    cin>>n;
    Ps a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=n-1;i>0;i--){
        for (int j=0;j<i;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
    for (int i=0;i<n;i++){
        cout<<rg(a[i])<<" ";
    }
    return 0;
}