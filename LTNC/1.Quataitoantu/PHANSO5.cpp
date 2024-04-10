#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;
struct Ps{
    int t,m;
};
istream& operator >>(istream& in,Ps &p){
    in>>p.t>>p.m;
    return in;
}
ostream& operator <<(ostream& out,Ps p){
    out<<p.t<<"/"<<p.m<<endl;
    return out;
}
Ps operator ++(Ps c){
    ++c.t;
    return c;
}
Ps operator --(Ps c){
    -- c.t;
    return c;
}
int main(){
    Ps a;
    cin>>a;
    cout<<a;
    string kt;
    cin.ignore();
    cin>>kt;
    if(kt=="++") cout<<++a;
    else if (kt=="--") cout<<--a;
    return 0;
}