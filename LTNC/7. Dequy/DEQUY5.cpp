#include<iostream>
#include<math.h>
using namespace std;
long long gt(int n){
    if(n==1) return 1;
    return n*gt(n-1);
}
double kq(int a,int b){
    if(b==0) return 1+a;
    return (pow(a*1.0,2*b+1)/gt(2*b+1)*1.0)+kq(a,b-1);
}
int main(){
    int a,b;
    cin>>a>>b;
    double c;
    c=kq(b,a);
    cout<<roundf(c * 1000) / 1000;
    return 0;
}