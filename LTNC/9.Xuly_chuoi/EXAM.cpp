
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int h1,m1,s1,h2,s2,m2,t,tong=0,tong2=0;
        int time=0;
        char c;
        cin>>h1>>c>>m1>>c>>s1>>h2>>c>>m2>>c>>s2>>t;
        t*=60;
        //cout<<h1*2<<" "<<m1*2<<" "<<s1*2<<" "<<h2*2<<" "<<m2*2<<" "<<s2*2;
        tong+=h1*3600+m1*60+s1;
        while(tong>=86400)
            tong%=86400;
        tong2+=h2*3600+m2*60+s2;
        if(tong2==tong)
            time+=24*3600;
        else
            if(tong2>tong)
                time=tong2-tong;
            else
                time=24*3600-tong+tong2;

        if(time==0)
            cout<<"Perfect";
        else
            if(time>=t)
                cout<<"Perfect";
            else
            {
                time+=3600;
                if(time>=t)
                    cout<<"Extra";
                else
                    cout<<"Fail";
            }
                
        cout<<endl;
    }
    return 0;
}