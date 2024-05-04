#include <iostream>
#include <vector>
using namespace std;

int main(){
  string s;
  cin >> s;
  int lens = s.size();
  int vitr = -1;
  for(int i = 0; i < lens; i++)
    if(int(s[i]) < int(s[i + 1])){
      vitr = i;
      break;
    }
  
  if(vitr == -1) s.erase(lens - 1, 1);
  else s.erase(vitr, 1);
  cout << s;
}