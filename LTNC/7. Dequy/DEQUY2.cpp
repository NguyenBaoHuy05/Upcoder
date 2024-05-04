#include<bits/stdc++.h>
using namespace std;
int hv(int n){
    if(n==1) return n;
    return n*hv(n-1);
}
void hvs(string &a,int index,vector<long> &b){
    if(index==a.size()-1){
        b.push_back(stol(a));
        return;
    }
    for(int i=index;i<a.size();++i){
        swap(a[index],a[i]);// Hoán đổi chữ số tại vị trí index và i
        // Gọi đệ quy để tạo các hoán vị tiếp theo bắt đầu từ vị trí index + 1
        hvs(a,index+1,b);// Phục hồi lại trạng thái ban đầu để tạo các hoán vị khác
        swap(a[index],a[i]);
    }
}
int main(){
    string a="";
    vector<long> b;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        a+=to_string(i);
    }
    cout<<hv(n)<<endl;
    hvs(a,0,b);
    sort(b.begin(),b.end());
    for(int i=0;i<b.size();++i){
        cout<<b[i]<<endl;
    }
    return 0;
}