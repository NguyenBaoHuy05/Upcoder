#include<iostream>
#include<math.h>
#include<vector>
const double PI = 3.14159;
using namespace std;
struct ToaDo {
     int x,y;
};
istream& operator>>(istream& in,ToaDo &x){
    in>>x.x>>x.y;
    return in;
}
struct VoiPhun {
    ToaDo o;
    int r;
};
istream& operator>>(istream& in,VoiPhun &x){
    in>>x.o>>x.r;
    return in;
}
double dt(VoiPhun a){
    return a.r*a.r*PI;
}
double operator +(VoiPhun a,VoiPhun b){
    return round((dt(a)+dt(b)) * 1000.0F) / 1000.0F;
}
double operator -(VoiPhun a,VoiPhun b){
    return sqrt((a.o.x-b.o.x)*(a.o.x-b.o.x)+(a.o.y-b.o.y)*(a.o.y-b.o.y));
}
bool operator &(VoiPhun a,VoiPhun b){
    return (a.r+b.r-(a-b)>0);
}
double trung(VoiPhun a,VoiPhun b){
    double d=a-b;
    double d1=(a.r*a.r-b.r*b.r+d*d)/(2*d);
    double d2=(-a.r*a.r+b.r*b.r+d*d)/(2*d);
    double an=a.r * a.r * acos(d1/a.r)-d1*sqrt(a.r*a.r-d1*d1)
    +b.r * b.r * acos(d2/b.r)-d2*sqrt(b.r*b.r-d2*d2);
}

int main(){
    VoiPhun a,b;
    cin>>a>>b;
    if(a&b) cout<<"A chong lap B";
    else "A khong chong lap B";
    cout<<endl;
    int c;double d=0,h=0;
    cin>>c;
    VoiPhun e[c];
    vector<bool> kt(c+1,1);
    for(int i=0;i<c;i++){
        cin>>e[i];
        d+=dt(e[i]);
    }
    for(int i=0;i<c-1;i++){
        if(kt[i]){
            for(int j=i+1;i<c;i++){
                if(kt[j]){
                if(e[i]&e[j]) {
                    kt[i]=0;
                    kt[j]=0;
                    cout<<"("<<i+1<<","<<j+1<<")"<<" ";
                    h+=trung(e[i],e[j]);
                    break;
                    } 
                }
            
            }

        }

    }
    cout<<endl;
    int f=round((d-h)*100/d-1.2);
    
    return 0;
}