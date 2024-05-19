#include<bits/stdc++.h>
using namespace std;
    string sdt[]={"04","08","059","061","0511","0710"};
    string matinh[]={"Ha Noi","TPHCM","Gia Lai","Dong Nai","Da Nang","Can Tho"};
bool hople(string str,string &strxl){
    if(str.size()!=10) return false;
    for(char c:str) if(!isdigit(c)) return false;
    string s=str.substr(0,4);
    bool kt=true;
    int ma;
    for(int i=0;i<6;i++){
        if(s.find(sdt[i])!=string::npos){
            kt=false;
            ma=i;
            break;
        }
    }
    
    if(kt) return false;
    else{
        strxl=matinh[ma]+" - "+str.substr(sdt[ma].size());
        return true;
    }
}
int main(){
    string s,str;
    cin>>s;
    if(!hople(s,str)) cout<<"Khong hop le";
    else cout<<str;
    return 0;
}