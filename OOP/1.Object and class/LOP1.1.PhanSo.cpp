#include<iostream>
using namespace std;
class Ps{
    private:
        int t,m;
    public:
        friend istream& operator>>(istream& in, Ps &a){
            in>>a.t>>a.m;
            return in;
        }
        friend ostream& operator<<(ostream& out,Ps a){
            out<<a.t<<"/"<<a.m;
        }
};
        

int main(){
    Ps a;
    cin>>a;
    cout<<a;
    return 0;
}