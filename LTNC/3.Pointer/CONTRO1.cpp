#include<iostream>
using namespace std;

int main(){
    int *p=new int [100],n,a[100],b[100];
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>*(p+i);
    }
    int max=p[0],min=p[0],j=0,k=0;
    for (int i=1;i<n;i++){
        if(max<p[i]) max=p[i];
        if (min>p[i]) min=p[i];
    }
    for (int i=0;i<n;i++){
        if(max==p[i]) {a[j]=i+1;j++;}
        if(min==p[i]) {b[k]=i+1;k++;}
    }
    cout<<max<<endl;
    for (int i=0;i<j;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<min<<endl;
    for (int i=0;i<k;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}