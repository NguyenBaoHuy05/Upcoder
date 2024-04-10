#include<iostream>
using namespace std;

int main(){
    int *p=new int[100],a,c=1;
    cin>>a;
    for (int i=1;i<=a;i++){
        cin>>*(p+i);
    }
    int b=a/2,k=0,n[100];
    
    while(c<b+1){
        if(p[c]!=p[a+1 - c]) {
            n[k]=c;
            k++;
        }
        c++;
    }
    if(k){
        cout<<"mang khong doi xung"<<endl;
        for (int i=0;i<k;i++){
            cout<<p[n[i]]<<" "<<p[a+1 - n[i]]<<endl;
        }
    }
    else cout<<"mang doi xung";
    return 0;
}