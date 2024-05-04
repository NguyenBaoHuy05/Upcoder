#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
    string s;
    int n,max=-1;
    stringstream ss,sss;
    while(cin>>s){
        reverse(s.begin(),s.end());
        ss<<s<<" ";
        ss>>n;
        if(n>max) max=n;
    }
    sss<<max;
    sss>>s;
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}