#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> a;
    int b;
    cin>>b;
    if(b==0) cout<<0;
    else{
    while(b){
        a.push(b%2);
        b/=2;
    }
    while(!a.empty()){
        cout<<a.top();
        a.pop();
    }
    }
    return 0;
}