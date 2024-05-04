#include<iostream>
#include<sstream>
using namespace std;
int main(){
    stringstream ss;
    string a;
    getline(cin,a);
    ss<<a;
    int dem=0;
    for(char x:a){
        if(x==' ') dem++;
    }
    int sl=0;
    while(sl<=dem){
        string s;
        ss>>s;
        cout<<s;
        if(sl==0 || sl==dem-1) cout<<endl;
        else cout<<" ";
        sl++;
    }
    return 0;
}