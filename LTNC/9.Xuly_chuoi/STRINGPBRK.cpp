#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,s1="";
    int max=0;
    while(cin>>s){
        if(s.find_first_of("bdfhkt")==string::npos) if(s.size()>max){
            max=s.size();
            s1=s;
        }
    }
    cout<<s1;
    return 0;
}
