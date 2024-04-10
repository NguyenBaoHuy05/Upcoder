#include<iostream>
using namespace std;
template<typename T>
struct M1C{
    T a[100];
    int n;
};
template<typename T>
istream& operator>>(istream& i,M1C<T> &a){
    a.n=0;
    while(i>>a.a[a.n]) a.n++;
    return i;
}
template<typename T>
ostream& operator<<(ostream& o,T a){
    for (int i=0;i<a.n;i++) o<<a.a[i];
    return o;
}
template<typename T>
void nhap(M1C<T> &a){

    cin>>a;
}
template<typename T>
void xuat(M1C<T> a){
    cout<<a;
}
template<typename T>
int tong(M1C<T> a){
    T b=a.a[0];
    for (int i=1;i<a.n;i++) b+=a.a[i];
    return b;
}
int main(){
    M1C<int> a;
    nhap(a);
    cout<<tong(a);
    return 0;
}