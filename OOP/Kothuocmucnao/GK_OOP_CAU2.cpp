#include<iostream>
#include<algorithm>
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
class str2:public str{
public:
    str2():str(){}
    str2(string b):str(b){}
    str2(const str2 &a):str(a){}
    ~str2(){}
    //
    void setstr2(string _a){ str::setstr(_a);}
    string getstr2(){return getstr();}
    //nhap
    friend istream& operator >>(istream& in,str2 &b){
        string a;
        getline(in,a);
        b=str2(a);
        return in;
    }
    friend ostream& operator <<(ostream& os,str2 b){
        os<<b.getstr()<<endl;
        return os;
    }
    ///
    bool operator > (str2 b){
        return getstr().size()>b.getstr().size();
    }
    bool operator < (str2 b){
        return getstr().size()<b.getstr().size();
    }
    int operator +(str2 b){
        return getstr().size()+b.getstr().size();
    }
    int operator -(str2 b){
        int a=getstr().size() - b.getstr().size();
        return abs(a);
    }
    ////
    string getStringInverse() {
        string temp = getstr(); // Tạo một bản sao của chuỗi
        reverse(temp.begin(), temp.end()); // Đảo ngược chuỗi
        return temp; // Trả về chuỗi đã đảo ngược
    }

};
int main(){
    str2 a,b;
    cin>>a>>b;
    cout<<a.getStringInverse()<<endl<<b.getStringInverse()<<endl;
    if(a<b) cout<<"BEHON";
    else if (a>b) cout<<"LONHON";
    else cout<<"BANG";
    cout<<endl;
    char c;
    cin>>c;
    if(c=='+') cout<<a+b;
    else cout<<a-b;
    return 0;
}