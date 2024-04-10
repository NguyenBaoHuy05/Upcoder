#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
bool kt(int a){
    if(a==2) return true;
    for (int i=2;i<sqrt(a)+1;i++){
        if(a%i==0) return false;
    }
    return true;
}
int main(){
    int a,b;
    bool *p=new bool[1000000];
    cin>>a>>b;
    for (int i=a;i<=b;i++){
        if(kt(i)) cout<<i<<" ";
    }
    delete[] p;
    return 0;
}