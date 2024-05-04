#include<iostream>
using namespace std;
int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    if(a.size()!=b.size()){
        cout<<"NO";
        return 0;
    }
    for(int i=0;i<a.size();i++){
        int j=0;
        while(j<b.size()){
            if(b[j]==a[i]) {
                b.erase(j,1);
                break;
            }
            j++;
        }
    }
    if(b.size()!=0) cout<<"NO";
    else cout<<"YES";
    return 0;
}