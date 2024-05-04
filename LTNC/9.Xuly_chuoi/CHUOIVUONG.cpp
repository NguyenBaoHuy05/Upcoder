#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s,s1;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s.size()%2==1) cout<<"NO";
        else{
            int a=s.size()/2;
            if(s.substr(0,a)==s.substr(a,a)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}