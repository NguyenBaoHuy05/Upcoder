#include<bits/stdc++.h>
using namespace std;
string s;
template<typename T>
struct Stack{
    vector <T>a;
    void init(){
        Stack();
    }
    void push(T c){
        a.push_back(c);
    }
    T top(){
        return a[a.size()-1];
    }
    void pop(){
        a.pop_back();
    }
    bool empty(){
        return a.empty();
    }
    void full(T k){
        for(int i=0;i<a.size();i++) a[i]=k;
    }
};
Stack <char>a;
int uutien(char a){
    if(a=='^') return 3;
    if(a=='*' || a=='/') return 2;
    else if(a=='+' || a=='-') return 1;
    return 0;
}
int main(){
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9') cout<<s[i];
        else if(s[i]=='(') a.push(s[i]);
        else if(s[i]==')'){
            while(a.top()!='('){
                cout<<a.top();
                a.pop();
            }
            a.pop();
        }
        else {
            if(!a.empty() && uutien(s[i])<=uutien(a.top())){
                    cout<<a.top();
                    a.pop();
            }
                a.push(s[i]);
        }
    }
    while(!a.empty()) {
        cout<<a.top();
        a.pop();
    }
    return 0;
}