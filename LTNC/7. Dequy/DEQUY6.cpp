#include<bits/stdc++.h>
using namespace std;
double gt(double n){
    if(n==1) return 1;
    return n*gt(n-1);
}
double res(double n,double x){
    if(n==0) return x;
    return pow((-1),n)*(pow(x,2*n+1)/gt(2*n+1))+res(n-1,x);
}
int main(){
    double n,x;
    cin >> n >> x;
    cout << roundf(res(n,x)*1000)/1000; 
    return 0;
}