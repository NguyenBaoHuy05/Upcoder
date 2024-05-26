#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &c:a) cin>>c;
    n-=1;
    if(n%2==1){
        sort(a.begin(),a.begin()+n/2+1);
        sort(a.begin()+n/2+1,a.end(),[](int a,int b){
            return a>b;
        });
    }
    else{
        sort(a.begin(),a.begin()+n/2);
        sort(a.begin()+n/2+1,a.end(),[](int a,int b){
            return a>b;
        });       
    }
    for(int c:a) cout<<c<<" ";
    return 0;
}