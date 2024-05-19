/*
As the title suggests, we can reverse numbers easily.
For example, the number 1234 reversed is 4321

Note, if a number is negative, the reverse is also negative.
For example, the reverse of -123 is -321

Additionally, all leading zeros must be removed before and after reversing the number (because leading zeros are meaningless).
For example, -1230 reversed is -321 (not -0321).

Your task is to find the inverse of the given integer n.

Input:
A single line is the integer n. ( |n| <= 101000). The integer n can contain leading zeros. You need to handle it.

Ouput:
Integer n after inversion. Note, you must remove meaningless leading zeros.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    
    while(str[str.size()-1]=='0') str.erase(str.size()-1,1);
    if(str[0]=='-'){
        while(str[1]=='0') str.erase(1,1);
        reverse(str.begin()+1,str.end());
    }
    else {
        while(str[0]=='0') str.erase(0,1);
        reverse(str.begin(),str.end());
    }
    
    cout<<str;
   
    return 0;
}