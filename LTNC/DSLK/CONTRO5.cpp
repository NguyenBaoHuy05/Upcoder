#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int n) : data(n), next(nullptr) {}
};

struct Link {
    Node* head;
    Link() : head(nullptr) {}
    
    void push(int n) {
        Node* node = new Node(n);
        if (head == nullptr) {
            head = node;
        } else {
            Node* tmp = head;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = node;
        }
    }

    void take(vector<int>& kp) {
        Node* tmp = head;
        while (tmp != nullptr) {
            kp.push_back(tmp->data);
            tmp = tmp->next;
        }
    }
};

int main() {
    Link list;
    vector<int> kp;
    bool kt = false;

    int k, n;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> n;
        list.push(n);
    }
    list.take(kp);
    
    if (kp.size() < 3) {
        cout << "NO" << endl;
        return 0;
    }

    // Sử dụng một map để lưu trữ các giá trị trong danh sách
    map<int, int> valueMap;
    for (int i = 0; i < kp.size(); i++) {
        valueMap[kp[i]] = i;
    }

    // Duyệt qua tất cả các cặp (b, c) và kiểm tra nếu a = b + c tồn tại trong map
    for (int i = 0; i < kp.size(); i++) {
        for (int j = i + 1; j < kp.size(); j++) {
            int a = kp[i] + kp[j];
            if (valueMap.find(a) != valueMap.end() && valueMap[a] != i && valueMap[a] != j) {
                kt = true;
                break;
            }
        }
        if (kt) break;
    }

    if (kt) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
