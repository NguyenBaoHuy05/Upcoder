#include<iostream>
using namespace std;
double kt(int n,int i){
    if(i==1) return n;
    if(i==2) return n+1;
    return kt(n,i-1)+kt(n,i-2);
}
double kt1(int n,int i){
    if(i==1) return (n+1);
    if(i==2) return (2*n+1);
    return kt1(n,i-1)+kt1(n,i-2);
}
int main(){
    int n;
    cin>>n;
    double a;
    a=kt1(n,n);
    cout<<a<<"/";
    a=kt(n,n);
    cout<<a;
    return 0;
}