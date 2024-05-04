#include<iostream>
#include<vector>
using namespace std;

bool kt(string luu, string s){
    int dem=0;
    for(int i=0;i<s.length();i++){
        if(luu[dem]==s[i]) dem++;
    }
    if(dem==luu.length()) return true;
    return false;
}
int main(){
    int n,sl=0;
    vector<int> a;
    cin>>n;
    cin.ignore();
    string luu="upcoder",b;
    for(int i=0;i<n;i++){
        getline(cin,b);
        if(kt(luu,b)) a.push_back(i);
    }    
    cout<<a.size()<<endl;
    for(int c:a) cout<<c+1<<" ";
    return 0;
}