#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    ifstream in("input.txt");
    ofstream out ("output.txt");
    while(getline(in,s)){
        while(s.find(" ")!=string::npos){
            s.erase(s.find(" "),1);
        }
        for(char &c:s) c=tolower(c);
        string k=s;
        reverse(k.begin(),k.end());
        if(k==s) out<<1;
        else out<<0;
        out<<endl;
    }
    in.close();
    out.close();
    return 0;
}