#include<iostream>
#include<cmath>
using namespace std;
struct date{
    int a,b,c;
};
istream& operator>>(istream& in,date &p){
    in>>p.a>>p.b>>p.c;
    return in;
}
ostream& operator<<(ostream& out,date p){
    if (p.a<10) out<<"0"<<p.a;
    else out<<p.a;
    out<<"/";
    if (p.b<10) out<<"0"<<p.b;
    else out<<p.b;
    out<<"/";
    out<<p.c<<" ";
}
bool kt(int a){
    return  (a%400==0 ||(a%4==0 and a%100!=0));
}
int ngay(date a){
    int n=a.a;
    for (int i=1;i<a.b;i++){
        switch (i)
        {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            n+=31;
            break;
        case 4:case 6:case 9:case 11:
            n+=30;
            break;
        case 2:
            n+=(kt(a.c))?29:28;
            break;
        default:
            break;
        }
    }
    return n;
}
int thu(date p){
    if (p.b<3) {
        p.b+=12;
        p.c-=1;
    }
    int n;
    n=(p.a+2*p.b+(3*(p.b+1))/5+p.c+(p.c/4))%7;
    return n;
}
date ketiep(date a){
    switch (a.b)
        {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            if (a.a<31) a.a++;
            else {
                if (a.b==12){
                    a.b=1;
                    a.c++;
                    a.a=1;
                }
                else{
                    a.a=1;
                    a.b++;
                }
            }
            break;
        case 4:case 6:case 9:case 11:
            if (a.a<30) a.a++;
            else {
                a.a=1;
                a.b++;
            }
            break;
        case 2:
            if(kt(a.c)){
                if (a.a<29) a.a++;
                else {
                        a.a=1;
                        a.b++;
                }
            }
            else {
                if (a.a<28) a.a++;
                else {
                        a.a=1;
                        a.b++;
                }
            }
            break;
        default:
            break;
        }
    return a;
}
bool operator ==(date a,date b){
    return  (a.c==b.c and ngay(a)==ngay(b));
}
bool trungthu(date a,date b){
    return (thu(a)==thu(b));
}
bool operator <(date a,date b){
    if (a.c>b.c) return false;
    else if(a.c<b.c) return true;
    else if(a.c==b.c){
        if((ngay(a) - ngay(b))>0) return false;
        else if((ngay(a) - ngay(b))<0) return true;
    }
}
int operator - (date a,date b){
    int z=0;
    date d,e;
    if(a.c>b.c) {d=a;e=b;}
    else {d=b;e=a;}
    for (int i=min(a.c,b.c);i<max(a.c,b.c);i++){
        if (kt(i)) ++z;
    }
    int c=abs(z*366+(abs(a.c-b.c)-z)*365+ngay(d)-ngay(e));
    return c;
}
void trx(int n){
    switch (n)
    {
    case 0:
        cout<<"Sunday";
        break;
    case 1:
        cout<<"Monday";
        break;
    case 2:
        cout<<"Tuesday";
        break;
    case 3:
        cout<<"Wednesday";
        break;
    case 4:
        cout<<"Thursday";
        break;
    case 5:
        cout<<"Friday";
        break;
    case 6:
        cout<<"Saturday";
        break;
    default:
        break;
    }
}
int main(){
    date a,b;
    cin>>a>>b;
    ///a
    cout<<a;
    trx(thu(a));
    cout<<" "<<ngay(a)<<" "<<ketiep(a)<<" ";
    if(kt(a.c)) cout<<"TRUE";
    else cout<<"FALSE";
    cout<<endl;
    ///b
    cout<<b;
    trx(thu(b));
    cout<<" "<<ngay(b)<<" "<<ketiep(b)<<" ";
    if(kt(b.c)) cout<<"TRUE";
    else cout<<"FALSE";
    cout<<endl;
    ////
    if(trungthu(a,b)) cout<<"TRUE";
    else cout<<"FALSE";
    cout<<endl;
    ////
    if(a<b) cout<<"1 < 2";
    else if(!(a<b) and !(a==b)) cout<<"1 > 2";
    else if(a == b) cout<<"1 = 2";
    cout<<endl;
    ///
    cout<<a - b;
    return 0;
}