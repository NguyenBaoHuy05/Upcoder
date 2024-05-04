#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<string> s;
    string a,b="";
    int dem;
    cin>>a;a+=a[a.size()-1];
    b=tolower(a[0]);
    for(int i=1;i<a.size();i++){
        if(a[i]!=a[i-1]){
            if(dem==1){
                b="";dem=0;
            }
            b+=a[i];
        }
        else {
            bool kt=true;
            for(int j=0;j<s.size();j++){
                if(b==s[j]) kt=false;
            }
            if(kt) s.push_back(b);
            dem=1;
        }
    }
    cout<<s.size();
    return 0;
}