#include<iostream>
using namespace std;


int main(){
    int *p=new int[100];
    int n,m,z=0,a[100];
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>*(p+i);
    }
    for (int i=0;i<n;i++){
        if(*(p+i)==m) a[z++]=i;
    }
    int k=z-1;
    while(k>-1){
        for(int i=a[k];i<n;i++){
            *(p+i)=*(p+i+1);
        }
        --k;--n;
    }
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
    return 0;
}