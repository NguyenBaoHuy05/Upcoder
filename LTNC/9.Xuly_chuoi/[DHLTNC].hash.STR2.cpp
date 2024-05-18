#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    getline(cin,s1);
    int b,maxx=0;
    cin>>b;
    cin.ignore();
    for(int i=0;i<b;i++){
        int a=0,dem=0;
        bool kt=true;
        getline(cin,s2);
        while(s1.find(s2,a)!=string::npos){
            a=s1.find(s2,a)+1;
            dem++;
        }
        maxx=max(maxx,dem);
    }
    cout<<maxx;
    return 0;
}