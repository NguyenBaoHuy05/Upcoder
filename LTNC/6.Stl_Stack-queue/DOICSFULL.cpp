#include<iostream>
#include<stack>
using namespace std;
void chuyenCoSo(int a,int b=0){
    stack<int> c;
    switch(b){
        case 0:
            while(a){
                c.push(a%2);
                a/=2;
            }
            break;
        case 1:
            while(a){
                c.push(a%8);
                a/=8;
            }
            break;
        case 2:
            while(a){
                c.push(a%16);
                a/=16;
            }
            break;
    }
    while(!c.empty()){
        if(c.top()>=10) cout<<char(55+c.top());
        else cout<<c.top();
        c.pop();
    }
    
}
int main(){
    int a,b;
    cin>>a>>b;
    chuyenCoSo(a,b);
    return 0;
}