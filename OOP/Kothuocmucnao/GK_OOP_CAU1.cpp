#include<iostream>
#include <string>
using namespace std;
class str{
    string a;
public:
    str(){
        a="";
    }
    str(string b){
        a=b;
    }
    str(const str &b){
        a=b.a;
    }
    ~str(){}
    ///
    void setstr(string _a){ a=_a;}
    string getstr(){return a;}
    //nhap
    friend istream& operator >>(istream& in,str &b){
        getline(in,b.a);
        return in;
    }
    friend ostream& operator <<(ostream& os,str b){
        os<<b.a<<endl;
        return os;
    }
    ///
    bool operator >(str b){
        return a.size()>b.a.size();
    }
    ////
    int getStringLength(){return a.size();}
    string stringUpperCase()    {for(char &x : a) x = toupper(x);return a;}
};
int main(){
    str a,b;
    cin>>a>>b;
    cout<<a<<b;
    if(a>b) {cout<<"YES"<<endl;cout<<a.stringUpperCase();}
    else {cout<<"NO"<<endl;cout<<b.stringUpperCase();}
    return 0;
}