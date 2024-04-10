#include<iostream>
using namespace std;
struct Sd{
    int a,b;
};
int daoso(int a){
    int b=0;
    while(a){
        b=b*10+a%10;
        a/=10;
    }
    return b;
}
istream& operator >>(istream& ib,Sd &s){
    ib>>s.a;
    s.b=daoso(s.a);
    return ib;
}
ostream& operator <<(ostream& ob,Sd s){
    ob<<"[SoDao] "<<s.a;
}
///
int operator +(int a,Sd b){
    a=a+b.b;
    return a;
}
bool operator <(Sd a,Sd b){
    return a.b<b.b;
}
template<typename T>
T max(T a[],int n){
    T max=a[0];
    for(int i=0;i<n;i++){
        if(max<a[i]) max=a[i];
        
    }
    return max;
}
template<typename T>
int tong(T a[],int n){
    int tong=0;
    for(int i=0;i<n;i++){
        tong=tong+a[i];
    }
    return tong;
}
void nhap(){
    char kt;
    int a[100];
    Sd b[100];
    int i=0,j=0;
    while(cin>>kt){
        if(kt=='T'){cin>>a[i]; i++;};
        if(kt=='D'){cin>>b[j]; j++;};
    }
    if(i==0) {
        cout<<" khong co"<<endl;
        cout<<" khong co"<<endl;
    }
    else
    {
        cout<<tong<int>(a,i)<<endl;
        cout<<max<int>(a,i)<<endl;
    }
    
    if(j==0) {
        cout<<" khong co"<<endl;
        cout<<" khong co"<<endl;
    }
    else
    {
        cout<<tong<Sd>(b,j)<<endl;
        cout<<max<Sd>(b,j)<<endl;
    }
    
}
int main(){
    nhap();
    return 0;
}