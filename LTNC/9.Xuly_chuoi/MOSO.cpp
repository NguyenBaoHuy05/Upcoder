#include<bits/stdc++.h>
using namespace std;
vector <string> k;
int main(){
    string s,num="0";
    long long maxx=0,dem=0;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            num+=s[i];
        }
        else if(num!=""){
            k.push_back(num);
            num="";
        }
    }
        if(num!=""){
            k.push_back(num);
            num="";
        }
    for(string c:k) {
        while(c[0]=='0'){
            if(c.size()==1) break;
            else {
                c.erase(0,1);
            }
        }
        if(num.size()<c.size() ||(num.size()==c.size() && num<c)) num=c;
    }
    cout<<num;
    return 0;
}