/*
The island of Arpa once again held an exam to select a ruler. The exam still has only one question: print the last digit of 1378 ^ n.
Mehrdad wants to win this contest so remember the help of Upcoder members..

Input:
Enter number n. (0 <= n <= 10100000)

Output:
Outputs the last digit of 1378^n.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin>>n;
    int dn[]={6,8,4,2},a;
    
    if(n=="0"){
        cout<<1;
        return 0;
    }
    if(n.size()<2){
        a=n[0]-'0';
        a=a%4;
    }
    else {
        int b=n[n.size()-2]-'0';
        int c=n[n.size()-1]-'0';
        a=b*10+c;
        a=a%4;
    }
    cout<< dn[a];
    
    return 0;
}