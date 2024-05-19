/*
Write a function to split an initial string into an array of substrings based on a specified delimiter character.

Note: before splitting the string, you must check if the string has many separator characters standing next to each other, or if there is a separator character standing at the beginning of the string, or at the end of the string, then you must remove the extra characters so that only There is 1 separating character between words, the beginning of the string and the end of the string do not have a separating character

Eg:

Original string: ",abc,,xyz,,,123,456,,"

Separator character: ,

String after removing extra characters: "abc,xyz,123,456"

Input:

First line: initial string

Second line: separator character

Output:

Number of substrings after splitting

The following lines are separable substrings
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str,s;
    char mid;
    getline(cin,str);
    
    cin>>mid;
    
    for(char &c:str) if(c==mid) c=' ';
    stringstream ss;
    
    ss<<str;
    
    int res=0;
    vector<string> save;
    
    while(ss>>s){
        res++;
        save.push_back(s);
    }
    
    cout<<res<<"\n";
    for(string c:save) cout<<c<<"\n";
    
    return 0;
}