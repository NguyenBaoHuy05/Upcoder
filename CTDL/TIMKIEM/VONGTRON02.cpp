#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,res=1;
    cin>>n>>k;
    int b[100],lee,sav=0;
    
    for(int i=0;i<k;i++) cin>>b[i];
    lee=b[0];
    queue<int> a;
    
    for(int i=0;i<n;i++) a.push(i);
    
    while(!a.empty()){
        if(res==lee){
            cout<<a.front()<<" ";
            a.pop();
            res=1;
            sav++;
            if(sav==k) sav=0;
            lee=b[sav];
        }
        else{
            a.push(a.front());
            a.pop();
            res++;
        }
        
    }
    return 0;
}