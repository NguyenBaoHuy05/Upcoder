#include<iostream>
using namespace std;
int dequy(long long n){
    int tong=0;
    if(n<10) return n;
    while(n){
        tong+=n%10;
        n/=10;
    }
    return dequy(tong);
}
int main(){
    long long n;
    cin>>n;
    cout<<dequy(n);
    return 0;
}