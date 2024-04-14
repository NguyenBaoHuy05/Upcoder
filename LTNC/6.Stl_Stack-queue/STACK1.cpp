#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char> s;
    char c;
    while(cin>>c){
        if(c=='*'){
            if(!s.empty()) {
                cout<<s.top();
                s.pop();
            }
        }
        else s.push(c);
    }
    return 0;
}