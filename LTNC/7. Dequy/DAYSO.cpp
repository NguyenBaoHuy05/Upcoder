#include<iostream>
using namespace std;
int so(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n%2==0) return so(n/2);
    if(n%2!=0) return so((n-1)/2)+so((n-1)/2+1);
}
int main(){
    int n,max=0;
    cin>>n;
    for(int i=0;i<=n;i++){
        max=(max<so(i))?so(i):max;
    }
    cout<<max;
    return 0;
}