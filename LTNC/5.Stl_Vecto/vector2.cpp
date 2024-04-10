#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define pb push_back
using namespace std;
int main(){
    string a,b;
    vector<int> c,d;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if (a[i]=='-' && a[i+1]=='1') {
            cout<<"empty";
            return 0;
        } 
        if(a[i]!=' ') {
            b=a[i];
            c.pb(stoi(b));
        }
    }
    int e;
    while(cin>>e) d.pb(e);
    if(c.size()==1 && c[0]!=-1) d.erase(d.begin()+c[0]);
    else {
        if(c.size()==2) for(int i=c[0];i<c[1];i++) d[i]=0;
        d.erase(remove_if(d.begin(),d.end(),[](int i){return !i;}),d.end());
    }
    if(d.size()==0 or c[0]==-1) cout<<"empty";
    else for(int x:d){
        cout<<x<<" ";
    }
    
    return 0;
}