#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<char> s;
    char c;
    while(cin>>c){
        if(c=='*'){
            if(!s.empty()) {
                cout<<s.front();
                s.pop();
            }
        }
        else s.push(c);
    }
    return 0;
}