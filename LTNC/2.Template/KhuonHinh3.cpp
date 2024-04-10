#include<iostream>
using namespace std;
struct ps{
    int t,m;
};
istream& operator>>(istream& in,ps &p){
    in>>p.t>>p.m;
    return in;
}
ostream& operator<<(ostream& out,ps p){
    out<<p.t<<"/"<<p.m;
    return out;
}
bool operator <(ps a,ps b){
    return (a.t*b.m<a.m*b.t);
}
struct mang{
    int a[100];
    float b[100];
    ps c[100];
};
template<typename T>
T max(T a[],int i){
    T b=a[0];
    for (int y=1;y<i;y++){
        if (a[y]<b) b=a[y];
    }
    return b;
}

int main(){
    char kt;
    int i=0,j=0,k=0;
    mang a;
    while(cin>>kt){
        if (kt=='a') cin>>a.a[i++];
        else if (kt=='b') cin>>a.b[j++];
        else if (kt=='c') cin>>a.c[k++];
    }
    if (i==0) cout<<"khong co"<<endl;
    else {
        cout<<max<int>(a.a,i)<<endl;
    }
    if (j==0) cout<<"khong co"<<endl;
    else {
        cout<<max<float>(a.b,j)<<endl;
    }
    if (k==0) cout<<"khong co"<<endl;
    else {
        cout<<max<ps>(a.c,k);
    }
    return 0;
}