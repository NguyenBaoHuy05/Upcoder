#include<bits/stdc++.h>
using namespace std;
vector <long long> k;
int n;
void Try(int j){
    if(j==n) return;
    if(j==1){
        k.push_back(1);
        Try(j+1);
        return;
    }
    vector<long long> h;
    h.push_back(1);
    for(int i=1;i<k.size();i++){
        h.push_back(k[i]+k[i-1]);
    }
    h.push_back(1);
    k=h;
    Try(j+1);
}
int main(){
    k.push_back(1);
    cin >> n;
    Try(1);
    for(long long x:k) cout<<x<<" ";
    return 0;
}