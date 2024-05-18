#include<iostream>
#include<vector>
using namespace std;
int dem=0;
vector <int> stt;
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

    bool take(){
        vector<int> kp;
        Node* tmp=head;
        while(tmp->next!=nullptr){
            kp.push_back(tmp->data);
            tmp=tmp->next;
        }
        kp.push_back(tmp->data);
        
        if(kp.size()<3) return false;

        for(int i=1;i<kp.size()-1;i++)
            if(kp[i]==kp[i-1]*kp[i+1]){
                dem++;
                stt.push_back(i+1);
            }
        if(dem==0) return false;
        else return true;       
    }
};
int main(){
    LinkedList list;
    int k,n;
    cin >> k;

    for(int i=0;i<k;i++) {
        cin>>n;
        list.push(n);
    }

    if(!list.take()) cout<<-1;
    else {
        cout<<dem<<endl;
        for(int l:stt) cout<<l<<" ";
    }
     
    return 0;
}