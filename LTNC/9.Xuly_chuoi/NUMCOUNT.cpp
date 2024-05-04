#include<iostream>
#include<sstream>
using namespace std;
int main(){
    string s,s1;
    while(getline(cin,s)){
        int luu=0,dem=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]) && isspace(s[i+1])) luu++;
        }
        cout<<luu+1<<endl;
    }
    return 0;
}