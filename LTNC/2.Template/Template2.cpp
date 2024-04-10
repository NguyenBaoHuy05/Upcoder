#include<iostream>
#include<algorithm>
using namespace std;
struct ps{
    int t,m;
};
istream& operator >>(istream& in,ps &p){
    in>>p.t>>p.m;
    return in;
}
ostream& operator <<(ostream& out,ps p){
    out<<p.t<<"/"<<p.m;
    return out;
}
ps operator +(ps a, ps b){
    a.t=a.t*b.m+a.m*b.t;
    a.m=a.m*b.m;
    return a;
}
ps rg(ps a){
    while(a.t*a.m){
        if(a.t>a.m) a.t=a.t%a.m;
        else a.m=a.m%a.t;
    }
    int ucln=(a.t>a.m)?a.t:a.m;
    int ucln=__gcd(a.t,a.m);
    a.t/=ucln;
    a.m/=ucln;
    return a;
}
template<typename T>
struct mang{
    T a[100];
};
template<typename T>
T tong(T a[],int i){
    T b=a[0];
    for (int z=1;z<i;z++) b=b+a[z];
    return b;
}
int main(){
    char kt;
    cin>>kt;
    int i=0;
    if(kt=='a'){
        mang<int> a;
        while(cin>>a.a[i]){
            i++;
        }
        cout<<tong<int>(a.a,i);
    }
    else if(kt=='b'){
        mang<ps> a;
        while(cin>>a.a[i]){
            i++;
        }
        cout<<rg(tong<ps>(a.a,i));
    }
    return 0;
}