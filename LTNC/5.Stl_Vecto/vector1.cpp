#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a;int i=0;
    while(cin>>i) a.push_back(i);
    vector<int>::iterator it;
    for ( it=a.begin();it!=a.end();it++){
        cout<<*it;
    }
    return 0;
}