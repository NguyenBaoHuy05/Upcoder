#include <iostream>

using namespace std;

/* Tính độ dài của dãy S(k) */
int len(int k){
	int x;
	if (k == -1) 
		return 0;
	x = len(k - 1);
	
	return x + k + 3 + x;
}

/* Trả về ký tự thứ n trong dãy S(k) */
char solve(int n, int k){
	if (n > len(k)) 
		return solve(n, k + 1);
	if (n <= len(k - 1)) 
		return solve(n, k - 1);
	n = n - len(k - 1); /* Bỏ đi dãy S(k-1) tính từ vị trí đầu tiên */
	if (n <= k + 3) /* kiểm tra xem n có nằm ở đoạn giữa hay không ? */
		return (n == 1) ? 'b' : 'o';
	n = n - (k + 3);
	return solve(n, k - 1);
}

int main(){
	long T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << solve(n, 0) << endl;
	}
	
	return 0;
}