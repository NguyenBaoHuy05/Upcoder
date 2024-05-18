#include<bits/stdc++.h>
using namespace std;
vector <string> k;
int main(){
    string s,num="",tmp="0";
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
    s="0";
    for(string c:k) {
        while(c[0]=='0'){
            if(c.size()==1) break;
            else {
                c.erase(0,1);
            }
        }
    }
    for(string c:k){
        int l=0,j=c.size();
        reverse(c.begin(),c.end());
        for(int i=0;i<c.size();i++){
            if(int(s[i])==0) s+='0';
            s[i]=char(s[i]+c[i]-'0'+l);
            if(s[i]-'0'>=10){
                l=1;
                s[i]=char(s[i]-10);
            }
            else l=0;
        }
        if(int(s[j])==0) s+='0';
        while(l==1){
            s[j]=char(s[j]+l);
            if(s[j]-'0'>=10){
                l=1;
                s[j]=char(s[j]-10);
            }      
            else l=0;
            j++;
        }
    }
    reverse(s.begin(),s.end());
        while(s[0]=='0'){
            if(s.size()==1) break;
            else {
                s.erase(0,1);
            }
        }
    cout<<s;
    return 0;
}