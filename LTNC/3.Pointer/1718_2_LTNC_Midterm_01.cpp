#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
struct SoPhuc{
    int t,a;
};
istream& operator >>(istream& i,SoPhuc &a){
    i>>a.t>>a.a;
    return i;
}
ostream& operator <<(ostream& o,SoPhuc a){
    o<<"{";
    if(a.t==0){
        if(abs(a.a)!=1 && a.a) o<<a.a<<"i";
        else if(!a.a) o<<0;
        else if(abs(a.a)==1) o<<(a.a>0?"":"-")<<"i";
    }
    else{
       o<<(a.t>0?"":"-")<<abs(a.t); 
       if(abs(a.a)!=1 && a.a) o<<(a.a>0?"+":"-")<<abs(a.a)<<"i";
        else if(!a.a) o<<"";
        else if(abs(a.a)==1) o<<(a.a>0?"+":"-")<<"i";
    }
    o<<"} ";
    return o;
}
float module(SoPhuc a){
    return sqrt(a.a*a.a+a.t*a.t);
}
SoPhuc operator +(SoPhuc a,SoPhuc b){
    a.t+=b.t;
    a.a+=b.a;
    return a;
}
int main(){
    SoPhuc a,*p=new SoPhuc[100];
    int i=0;
    while(cin>>*(p+i)){
        i++;
    }
    for (int z=0;z<i;z++){
        cout<<*(p+z);
    }
    cout<<endl;
    
    for (int z=0;z<i;z++){
        cout<<fixed<<setprecision(2)<<module(*(p+z))<<" ";
    }
    cout<<endl;
    a=*p;
    for (int z=1;z<i;z++){
        a=a+p[z];
    }
    cout<<a;
    return 0;
}