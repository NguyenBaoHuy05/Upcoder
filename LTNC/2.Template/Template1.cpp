#include<iostream>
using namespace std;

struct Ps{
    int t,m;
};
istream& operator >> (istream& in,Ps &p){
    in>>p.t>>p.m;
    return in;
}
ostream& operator << (ostream& out,Ps p){
    out<<p.t<<"/"<<p.m;
    return out;
}
bool operator <(Ps a,Ps b){
    if((a.t*b.m-a.m*b.t)<0) return true;
    else  return false;

}
template <typename T>
T Max(T a,T b,T c){
    T max=a;
    if(max<b) max=b;
    if (max<c) max=c;
    return max;
}
template <typename T>
void Xuat(){
    T a,b,c;
    cin>>a>>b>>c;
    cout<<Max(a,b,c);
}

int main(){
    char kt;
    cin>>kt;
    if(kt=='a'){
        Xuat<int>();
    }
    else if(kt=='b'){
        Xuat<float>();
    }
    else if(kt=='c'){
        Xuat<Ps>();
    }
    return 0;
}