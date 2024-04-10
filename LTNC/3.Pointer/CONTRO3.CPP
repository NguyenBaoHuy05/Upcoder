#include<iostream>
using namespace std;


int main(){
    int *p=new int[100];
    int n,m,z;
    cin>>n>>m>>z;
    for (int i=0;i<n;i++){
        cin>>*(p+i);
    }
    for(int i=n;i>z-1;i--){
        *(p+i)=*(p+i-1);
    }
    p[z-1]=m;
    ////
    cout<<n+1<<endl;
    for (int i=0;i<=n;i++){
        cout<<*(p+i)<<" ";
    }
    return 0;
}