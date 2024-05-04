#include<iostream>
using namespace std;
int dequy(int n,int k){
    if(k==0 || k==n){
        return 1;
    }
    return dequy(n-1,k)+dequy(n-1,k-1);
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<dequy(n,k);
    return 0;
}