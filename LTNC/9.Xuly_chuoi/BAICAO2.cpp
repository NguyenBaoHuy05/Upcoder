#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
stringstream ss;
string s;
int a[6],j=0,max=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin.ignore();
        while(getline(cin,s)){
            int chu=0,sum=0;
            ss.clear(); // Xóa trạng thái lỗi của stringstream
            ss.str(s);  // Đặt stringstream để sử dụng chuỗi mới
    
            for(int i=0;i<3;i++){
                ss>>s;
                if(!isdigit(s[0])) {
                    chu++;
                    if(s[0]=='A') sum+=1;
                    else sum+=10;
                }
                else sum+=stoi(s);
            }
            if(chu==3) a[j]=10;
            else a[j]=sum%10;
            if(a[j]>max) max=a[j];
            j++;
        }
        for(int i=0;i<6;i++){
            if(a[i]==max){
                switch(i){
                    case 0:
                        cout<<"Dau ";
                        break;                
                    case 1:
                        cout<<"Su ";
                        break;
                    case 2:
                        cout<<"Lu ";
                        break;
                    case 3:
                        cout<<"Bu ";
                        break;
                    case 4:
                        cout<<"Ti ";
                        break;
                    default:
                        cout<<"Teo ";
                        break;
                }
            }
        }
    }
    return 0;
}