#include<iostream>
#include<algorithm>
using namespace std;
struct ps{
    int t,m;
    
    ps operator +=(ps a){
        t=t*a.m+m*a.t;
        m=a.m*m;
        return *this;
    }
};
istream& operator>>(istream& i,ps &a){
    i>>a.t>>a.m;
    return i;
}
ostream& operator<<(ostream& o,ps a){
    o<<a.t<<"/"<<a.m;
    return o;
}
ps rg(ps a){
        int ucln=__gcd(a.t,a.m);
        a.t/=ucln;
        a.m/=ucln;
        return a;
}
template<typename T>
T tong(T a[],int n){
    T b=a[0];
    for (int i=1;i<n;i++){
        b+=a[i];
    }
    return b;
}


int main(){
    int a[100],i=0,j=0;
    ps b[100];
    char c;
    
    while(cin>>c){
        if(c=='a'){
            cin>>a[i++];
        }
        else if(c=='b'){
            cin>>b[j++];
        }
    }
    if(!i) cout<<"khong co";
    else cout<<tong<int>(a,i);
    cout<<endl;
    if(!j) cout<<"khong co";
    else cout<<rg(tong<ps>(b,j));
    return 0;
}