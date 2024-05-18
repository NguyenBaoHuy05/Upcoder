#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > s;
vector<int> l;
int a[100];
int sum=0;
void Try(int j,int k){
    if(k==0){
        if(sum%2==1){
            s.push_back(l);
        }
        return;
    }
    for(int i=j;i<n;i++){
        sum+=a[i];
        l.push_back(a[i]);
        Try(i+1,k-1);
        l.pop_back();  // Xóa phần tử vừa thêm vào
        sum-=a[i];
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        Try(0,i);
    }
    sort(s.begin(),s.end());
    if(s.empty()) cout<<-1;
    else for(vector<int> c:s){
        for(int i:c) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}