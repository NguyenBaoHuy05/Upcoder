#include<iostream>
using namespace std;
int n;
int a[100],dp[100];
int Rabber(){
    if(n==0) return 0;
    if(n==1) return a[0];
    dp[0]=a[0];
    dp[1]=max(a[0],a[1]);
    
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],a[i]+dp[i-2]);
    }
    return dp[n-1];
    
}
int main(){
    cin >> n;
    
    for(int i=0;i<n;i++) cin>>a[i];
    
    cout<<Rabber();
    return 0;
}