#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int max=0;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int dem=0;
        for(int j=0;j<n;j++){
            if(a[j][i]) dem++;
            else {
                if(dem>max) max=dem;
                dem=0;
            }
        }

    }
    for(int i=0;i<n;i++){
        int dem=0;
        for(int j=0;j<n;j++){
            if(a[i][j]) dem++;
            else {
                if(dem>max) max=dem;
                dem=0;
            }
        }

    }
    int dem1=0;
    for(int i=0;i<n;i++){
        int dem=0;
        for(int j=0;j<=dem1;j++){
            cout<<j<<"-"<<i-j<<" ";
            if(a[j][i-j]) dem++;

            else {
                if(dem>max) max=dem;
                dem=0;
            }
        }
        cout<<endl;
        dem1++;
    }
    // int dem2=0;
    // for(int i=n-1;i>=0;i++){
    //     int dem=0;
    //     for(int j=0;j<=dem2;j++){
    //         dem+=a[i+j][j];
    //     }
    //     dem2++;
    //     if(dem>max) max=dem;
    // }
    cout<<max;
    return 0;
}