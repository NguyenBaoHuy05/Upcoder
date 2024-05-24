#include<bits/stdc++.h>
using namespace std;
    char a;
    int n;
int main(){
    cin>>a>>n;
    vector<char> b(n);
    
   for(char &c:b) cin>>c;
    if(a=='A')
    sort(b.begin(),b.end(),[] (int i,int j){
       return i<j ;
    });
    else
    sort(b.begin(),b.end(),[] (int i,int j){
     return i>j;
    });
    for(char c:b) cout<<c<<" ";
    return 0;
}