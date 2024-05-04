#include<iostream>
#include<sstream>
using namespace std;
int main(){
    string a,b;
    stringstream ss;
    while(cin>>a) {
        ss<<a<<" ";
        ss>>b;
        if(b.find("@gmail.com")!=string::npos) cout<<b<<endl;
    }
    return 0;
}