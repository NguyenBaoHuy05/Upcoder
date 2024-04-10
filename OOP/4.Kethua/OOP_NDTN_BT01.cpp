#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class BankAccount{
    string ID,CustomerName,IDCardNumber;
    double Balance,WithdrawLimit;
public:
////get-set
    void setID(string a)              {ID=a;}
    string getID()                    {return ID;}
    void setCustomerName(string a)    {CustomerName=a;}
    string getCustomerName()          {return CustomerName;}
    void setIDCardNumber(string a)    {IDCardNumber=a;}
    string getIDCardNumber()          {return IDCardNumber;}
    void setBalance(double a)         {Balance=a;}
    double getBalance()               {return Balance;}
    void setWithdrawLimit(double a)   {WithdrawLimit=a;}
    double getWithdrawLimit()         {return WithdrawLimit;}
    //khoitao
    BankAccount(){
        ID="000000";
        CustomerName="No name";
        IDCardNumber="xxx";
        Balance=0;
    }
    BankAccount(string id,string customerName,string idCardNumber,double Money){
        ID=id;
        CustomerName=customerName;
        IDCardNumber=idCardNumber;
        Balance=Money;
    }
    bool Withdraw(double withdrawmoney){
        return withdrawmoney<=WithdrawLimit;
    }
    double Deposit(double depositmoney){
        return Balance+depositmoney;
    }

    
};
class ChekingAccount:public BankAccount{
    double OverDraftLimit;
    double withdraw;
public:
///
    void setwithdraw(double a)    {withdraw=a;}
    double getwithdraw()          {return withdraw;}   
///
    ChekingAccount(string id, string customerName, string idCardNumber,
               double Money, double overDraftLimit)
    : BankAccount(id, customerName, idCardNumber, Money) {
    setWithdrawLimit(overDraftLimit+getBalance());
}
    ChekingAccount(){
        setWithdrawLimit(50000);
    }
    ////
    friend istream& operator >>(istream& in,ChekingAccount &a){
        string id,customerName,idCardNumber,rong;
        char chua;
        double Money,overDraftLimit,dem=1,withdraw;
        in.ignore();
            getline(in,id,'/');
            getline(in,customerName,'/');
            getline(in,idCardNumber,'/');
            getline(in,rong,'/');
        Money= stod(rong);
        getline(in,rong);
        overDraftLimit= stod(rong);
        in>>withdraw;
        a=ChekingAccount(id,customerName,idCardNumber,Money,overDraftLimit);
        a.setwithdraw(withdraw);
        return in;
    }
    friend ostream& operator <<(ostream& os,ChekingAccount a){
        os<<"{"<<a.getID()<<"}:{"<<a.getCustomerName()<<"}:{"<<fixed << std::setprecision(0)<<a.getBalance()<<"}"<<endl;
        if(a.Withdraw(a.withdraw)) cout<<"Yes {"<<a.getID()<<"}:{"<<a.getCustomerName()<<"}:{"<<a.getBalance()-a.withdraw<<"}";
        else cout<<"No ";
        os<<endl;
        os<<"Checking Account";
        return os;
    }
};
class SavingAccount:public BankAccount{
    double InterestRate;
    double InterestMoney;
    double withdraw;
public:
///
    void setwithdraw(double a)          {withdraw=a;}
    double getwithdraw()                {return withdraw;} 
    void setInterestRate(double a)      {InterestRate=a;}
    double getInterestRate()            {return InterestRate;}
    void setInterestMoney(double a)     {InterestMoney=a;}
    double getInterestMoney()           {return InterestMoney;}     
///
    SavingAccount(string id, string customerName, string idCardNumber,
               double Money)
    : BankAccount(id, customerName, idCardNumber, Money) {
    setWithdrawLimit(getBalance());
}
    SavingAccount(){}
    ~SavingAccount(){}
    ////
    friend istream& operator >>(istream& in,SavingAccount &a){
        string id,customerName,idCardNumber,rong;
        char chua;
        double Money,overDraftLimit,withdraw;
        in.ignore();
        getline(in,id,'/');
        getline(in,customerName,'/');
        getline(in,idCardNumber,'/');
        getline(in,rong);
        Money= stod(rong);
        a=SavingAccount(id,customerName,idCardNumber,Money);
        in>>withdraw;
        a.setwithdraw(withdraw);
        return in;
    }
    friend ostream& operator <<(ostream& os,SavingAccount a){
        os<<"{"<<a.getID()<<"}:{"<<a.getCustomerName()<<"}:{"<<fixed << std::setprecision(0)<<a.getBalance()<<"}"<<endl;
        if(a.Withdraw(a.withdraw))
        {cout<<"Yes {"<<a.getID()<<"}:{"<<a.getCustomerName()<<"}:{"<<a.getBalance()-a.withdraw<<"}";a.setBalance(a.getBalance()-a.withdraw);}
        else cout<<"No ";
        os<<endl;
        if(a.getBalance()<1000000)          a.setInterestRate(0.1);
        else if(a.getBalance()<50000000)    a.setInterestRate(0.3);
        else if(a.getBalance()<200000000)   a.setInterestRate(0.5);
        else if(a.getBalance()<1000000000)  a.setInterestRate(1);
        else a.setInterestRate(1.94);
        a.setInterestMoney(a.getBalance()*a.getInterestRate());
        os<<"{"<<a.getID()<<"}:{"<<a.getCustomerName()<<"}:{"<<fixed << std::setprecision(0)<<a.getBalance()+a.getInterestMoney()<<"}"<<endl;
        return os;
    }
};
int main(){
    char kt;
    cin>>kt;
    if(kt=='C'){
        ChekingAccount a;
        cin>>a;
        cout<<a;
    }
    else if(kt=='S'){
        SavingAccount a;
        cin>>a;
        cout<<a;
    }
    return 0;
}