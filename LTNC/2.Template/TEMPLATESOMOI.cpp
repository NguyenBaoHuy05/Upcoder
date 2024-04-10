#include<iostream>
using namespace std;
struct Sm{
    int a,b;
};
int tcs(int a){
    int b=0;
    while(a){
        b+=a%10;
        a/=10;
    }
    return b;
}
istream& operator >>(istream& ib,Sm &s){
    ib>>s.a;
    s.b=tcs(s.a);
    return ib;
}
ostream& operator <<(ostream& ob,Sm s){
    ob<<"[SoMoi] "<<s.a;
}

template<typename T>
struct Mang{
    T a[1000];
    
};
Sm operator +(Sm a,Sm b){
    a.b=a.b+b.b;
    a.a=a.b;
    return a;
}
bool operator ==(Sm a,Sm b){
    return a.a==b.a;
}
bool operator <(Sm a,Sm b){
    if(b.b==a.b && a.a<b.a) return true;
    return a.b<b.b;
}
template<typename T>
T max(Mang<T> a,int n){
    T max=a.a[0];
    for(int i=1;i<n;i++){
        if(max<a.a[i]) max=a.a[i];
        
    }
    return max;
}
template<typename T>
T tong(Mang<T> a,int n){
    T tong=a.a[0];
    for(int i=1;i<n;i++){
        tong=tong+a.a[i];
    }
    return tong;
}
template<typename T>
int tc(Mang<T> a,int n){
    int dem=0;
    T nhan=max<T>(a,n);
    for(int i=0;i<n;i++){
        if(nhan==a.a[i]) dem++;
    }
    return dem;
}
template<typename T>
void nhap(){
    Mang<T> ma;int n=0;
    while(cin>>ma.a[n]) n++;
    cout<<max<T>(ma,n)<<endl;
    cout<<tc<T>(ma,n)<<endl;
    cout<<tong<T>(ma,n);
}
int main(){
    char kt;
    cin>>kt;
    if(kt=='N'){
        nhap<int>();
    }
    else if(kt=='M'){
        nhap<Sm>();
    }
    return 0;
}