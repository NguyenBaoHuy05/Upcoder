#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,res=1;
    cin>>n>>k;
    queue<int> a;
    
    for(int i=0;i<n;i++) a.push(i);
    
    while(!a.empty()){
        if(res==k){
            cout<<a.front()<<" ";
            a.pop();
            res=1;
        }
        else{
            a.push(a.front());
            a.pop();
            res++;
        }
        
    }
    return 0;
}