#include<iostream>
#include<cmath>
using namespace std;
class Arr{
    int p;
    int a[100];
    public:
        ~Arr(){}
        void set(int a){
            p=a;
        }
        int get(){
            return p;
        }
        friend istream& operator >>(istream& in,Arr &p){
            for (int i=p.p-1;i>=0;i--){
                in>>p.a[i];
                return in;
            }
        }
        friend ostream& operator <<(ostream& in,Arr p){
            for (int i=p.p-1;i>=0;i--){
                in<<p.a[i]<<" ";
                return in;
            }
        }
        friend Arr operator -(const Arr &a,const Arr &b){
            Arr c;
            for (int i=0;i<min(a.p,b.p);i++){
                c.a[i]=abs(a.a[i]-b.a[i]);
            }
            if(a.p>b.p){
                for(int i=b.p;i<a.p;i++){
                    c.a[i]=a.a[i];
                }
            }
            else if(a.p<b.p){
                for(int i=a.p;i<b.p;i++){
                    c.a[i]=b.a[i];
                }
            }
            c.p=max(a.p,b.p);
            return c;

        }
        int chuyen(){
            int z=0;
            for (int i=0;i<p;i++){
                z=z*10+a[i];
                return z;
            }
        }

};

int main(){
    int a,b;
    cin>>a>>b;
    Arr c,d,e;
    c.set(a);
    d.set(b);
    e=c-d;
    cout<<e.get()<<":"<<e.chuyen();
    return 0;
}