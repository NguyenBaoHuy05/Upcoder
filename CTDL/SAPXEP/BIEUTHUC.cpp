#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,res;
    long long sum;
    cin >> n >> k;
    vector<int> a(n);
    
    for(int &c:a) cin>>c;
    int l=a[0];
    
    sort(a.begin()+1,a.end(),[](int x,int y) {return x>=y;});
    
    sum=a[0];
    res=1;
    while(k--){
        sum+=a[res];
        res++;
    }
    for(int i=res;i<a.size();i++) sum-=a[i];
    cout<<sum;
    return 0;
}