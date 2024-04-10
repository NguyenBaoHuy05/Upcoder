#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int total=a+b;
    ofstream output ("out.txt");
    output<<total;
    output.close();
    return 0;
}