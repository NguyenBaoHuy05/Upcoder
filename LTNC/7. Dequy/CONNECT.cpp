#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm so sánh để sắp xếp các số
bool compare(string a, string b) {
    return a + b > b + a;
}

int main() {
    ifstream infile("CONNECT.INP");
    ofstream outfile("CONNECT.OUT");

    int n;
    infile >> n;
    vector<string> numbers(n);
    for (int i = 0; i < n; ++i) {
        infile >> numbers[i];
    }
    sort(numbers.begin(), numbers.end(), compare);
    string result;
    for (int i = 0; i < n; ++i) {
        result += numbers[i];
    }
    outfile << result << endl;
    infile.close();
    outfile.close();

    return 0;
}
