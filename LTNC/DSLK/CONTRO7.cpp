#include<bits/stdc++.h>
using namespace std;
int dem=0,minn=10000;
vector <int> stt;
struct td{
    int a, b;
};
vector <td> k;
struct Node{
  int data;
  Node* next;
  Node(int n):data(n),next(nullptr){}
};
struct LinkedList{
    Node* head;
    LinkedList():head(nullptr){}

    void push(int n){
        Node* node= new Node(n);
        if(head==nullptr){
            head=node;
        }
        else{
            Node* tmp=head;
            while(tmp->next!=nullptr){
                tmp=tmp->next;
            }
            tmp->next=node;
        }
    }

    void take() {
        vector<int> kp;
        Node* tmp = head;
        while (tmp->next != nullptr) {
            kp.push_back(tmp->data);
            tmp = tmp->next;
        }
        kp.push_back(tmp->data);
    
        // Tính giá trị minn
        for (int i = 0; i < kp.size(); i++) {
            for (int j = i + 1; j < kp.size(); j++) {
                minn = min(minn, abs(kp[i] - kp[j]));
            }
        }
    
        // Đếm số cặp phần tử có khoảng cách tuyệt đối bằng minn
        for (int i = 0; i < kp.size(); i++) {
            for (int j = i + 1; j < kp.size(); j++) {
                if (abs(kp[i] - kp[j]) == minn) {
                    dem++;
                    if (kp[i] <= kp[j]) k.push_back({kp[i], kp[j]});
                    else k.push_back({kp[j], kp[i]});
                }
            }
        }
    }

};
int main(){
    ifstream cin("CONTRO.inp");
    ofstream cout("CONTRO.out");


    LinkedList list;
    int h,n;
    cin >> h;

    for(int i=0;i<h;i++) {
        cin>>n;
        list.push(n);
    }

    list.take();
    cout<<dem<<" "<<minn<<endl;
    
    for(int i=0;i<k.size();i++) {
        cout << "(" << k[i].a << ", " << k[i].b << ") ";
    }

    
    cin.close();
    cout.close();
    return 0;
}