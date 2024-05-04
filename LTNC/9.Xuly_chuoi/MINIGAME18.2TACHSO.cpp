#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    int sum=0;
    while(getline(cin,a,',')){
        cout<<a<<endl;
        sum+=stoi(a);
    }
    cout<<sum;
    return 0;
}