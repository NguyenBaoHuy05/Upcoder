#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
double gt(double n){
    if(n==1) return 1;
    return n*gt(n-1);
}
double sinn(double n,double k){
    if(n==0) return k;
    double x=0;
    return pow((-1),n)*(pow(k,2*n+1)/gt(2*n+1))+sinn(n-1,k);
}
double coss(double n,double k){
    if(n==0) return 1;
    double x=0;
    return pow((-1),n)*(pow(k,2*n)/gt(2*n))+coss(n-1,k);
}
int main(){
    double n;
    cin>>n;
    double si=sinn(5,n),co=coss(5,n);
    cout<<roundf(si * 100) / 100<<endl;
    cout<<roundf(co * 100) / 100<<endl;
    return 0;
}