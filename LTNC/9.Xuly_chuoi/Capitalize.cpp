#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if((isspace(a[i]) && isalpha(a[i+1]))) a[i+1]=toupper(a[i+1]);
        else a[i+1]=tolower(a[i+1]);
    }
    a[0]=toupper(a[0]);
    cout<<a;
    return 0;
}