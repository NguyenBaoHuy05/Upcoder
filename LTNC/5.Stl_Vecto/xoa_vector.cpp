#include<iostream>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;
vector<int> a,b;
int main(){
    int n,k;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>k;
        a.pb(k);
    }
    while(cin>>k) b.pb(k);
    if(b.size()==1 && b[0]!=-1) a.erase(a.begin()+b[0]);
    else if(b.size()==2) {
        for(int i=b[0];i<b[1];i++) a[i]=0;
        a.erase(remove_if(a.begin(),a.end(),[](int i) {return !i;} ),a.end());
    }
    if(a.size()==0 or b[0]==-1) cout<<"empty";
    else
    for(int x:a){
        cout<<x<<" ";
    }
    return 0;
}