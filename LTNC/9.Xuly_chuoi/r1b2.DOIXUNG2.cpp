#include <iostream>
#include <string>

using namespace std;

string s;
int d, res;
bool flag;

int main(){
	cin >> s;
	
	int n = s.length();
	for (int i = 0; i < n; i++){
		for (int j = n - 1; j >= i + 1; j--){
			if (s[i] == s[j]){
				flag = true;
				for (int k = 0; k <= (j - i) / 2; k++){
					if (s[i + k] != s[j - k]){
						flag = false;
						break;
					}
				}
				if (flag){
					d = j - i + 1;
					if (res < d)
						res = d;
				}
			}
		}
	}
	cout << ((res==0)?1:res);

	return 0;
}