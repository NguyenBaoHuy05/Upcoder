#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++) cin>>a[i];
    
    int max_length=0;
    for(int i=0;i<n;i++){
        int low=i,high=i;
        int res=a[i];
        while(low>=0 && high<n && a[low]==res && a[high]==res){
            if(high-low+1>max_length){
                max_length=high-low+1;
            }
            low--;
            high++;
        }
        low=i,high=i+1;
        res=a[i];
        while(low>=0 && high<n && a[low]==res && a[high]==res){
            if(high-low+1>max_length){
                max_length=high-low+1;
            }
            low--;
            high++;
        }
    }
    cout<<n-max_length;
    return 0;
}