#include<iostream>
using namespace std;

int main(){
    int **p=new int*[100],a;
    cin>>a;
    for (int i=0;i<100;i++){
        p[i]=new int[100];
    }
    for (int i=0;i<a;i++){
        for (int j=0;j<a;j++){
            if(j==i) p[i][j]=1;
            else p[i][j]=0;
        }
    }
    for (int i=0;i<a;i++){
        for (int j=0;j<a;j++) cout<<p[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}