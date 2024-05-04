#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
int main(){
    int a;
    cin>>a;
    stack<int> s;
    for(int i=0;i<pow(2.0,a);i++){
        int c=i;
        int dem=0;
        while(dem<a){
            s.push(c%2);
            c/=2;
            dem++;
        }
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}