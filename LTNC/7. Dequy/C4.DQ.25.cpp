#include<iostream>
using namespace std;
int dequy(int n){
    if(n==0||n==1) return 1;
    int tong=0;
    for(int i=0;i<n;i++){
        tong+=dequy(i)*dequy(n-i-1);
    }
}
int main(){
    int n;
    while(cin>>n){
        cout<<dequy(n)<<endl;
    }
    return 0;
}