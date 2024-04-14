#include<iostream>
#include<stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    char c;
    while(cin>>c){
        if(s.empty()) s.push(c);
        else {
            if(
                (s.top()=='{' && c=='}')||
                (s.top()=='[' && c==']')||
                (s.top()=='(' && c==')')
            ) s.pop();
            else s.push(c);
        }
    }
    if(s.empty()) cout<<"yes";
    else cout<<"no";
    return 0;
}