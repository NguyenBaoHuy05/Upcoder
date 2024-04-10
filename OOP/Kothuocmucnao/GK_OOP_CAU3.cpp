#include<iostream>
#include<algorithm>
#include <string>
#include<iomanip>
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
class  str3:public str2{
public:
    str3():str2(){}
    str3(string b):str2(b){}
    str3(const str3 &a):str2(a){}
    ~str3(){}
    //
    void setstr3(string _a){ str::setstr(_a);}
    string getstr3(){return getstr();}
    //nhap
    friend istream& operator >>(istream& in,str3 &b){
        string a;
        getline(in,a);
        b=str3(a);
        return in;
    }
    friend ostream& operator <<(ostream& os,str3 b){
        os<<b.getstr()<<endl;
        return os;
    }
    ///
    bool operator > (str3 b){
        return getstr().size()>b.getstr().size();
    }
    bool operator < (str3 b){
        return getstr().size()<b.getstr().size();
    }
    int operator +(str3 b){
        return getstr().size()+b.getstr().size();
    }
    int operator -(str3 b){
        int a=getstr().size() - b.getstr().size();
        return abs(a);
    }
    ////
    string deleteIn(string a){
        while (!a.empty() && isspace(a.front())) {
        a.erase(0, 1);
    }
    int dem=0;string d="";
    // Loại bỏ khoảng trắng từ cuối chuỗi
    while (!a.empty() && isspace(a.back())) {
        a.pop_back();
    }
    for(char c:a){
        if(c==' ') dem++;
        else dem=0;
        if(dem<2) d+=c;
    }
    return d;
    }
    string getStringInverse() {
        string temp = getstr(); // Tạo một bản sao của chuỗi
        temp=deleteIn(temp);
        
        reverse(temp.begin(), temp.end()); // Đảo ngược chuỗi
        return temp; // Trả về chuỗi đã đảo ngược
    }
    string connectString(string s){
        return (deleteIn(getstr())+" "+deleteIn(s));
    }

};
int main(){
    str3 a,b;
    cin>>a>>b;
    cout<<a.connectString(b.getstr())<<endl;
    cout<<a.getStringInverse()<<endl;
    cout<<b.getStringInverse()<<endl;
    cout<<fixed<<setprecision(2)<<a.getStringInverse().size()*1.0/b.getStringInverse().size();
    return 0;
}