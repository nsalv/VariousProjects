#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class BankAccount{
public:

int BankId, accnum, time;
bool open;
double profit, interest, balance;
double loanint = .1;

BankAccount ()
{
    open=true;
    interest=0;
    BankId=0;
    time=0;

    if (balance>0){
        //for calculation of bank profits
        profit-= balance*pow((1+interest),time);
        balance += balance*pow((1+interest),time);
    }
    if (balance<0){
    //for calculation of bank profits
        profit+= -balance*pow((1+loanint),time);
        balance -= -balance*pow((1+loanint),time);
    }

}

//constructor requires three arguments, not two
BankAccount (double bal, double inter, int Id)
{
    open=true;
    balance = bal;
    interest = inter;
    BankId = Id;
    time=0;

    if (balance>0){
        //for calculation of bank profits
        profit-= balance*pow((1+interest),time);
        balance += balance*pow((1+interest),time);
    }
    if (balance<0){
        //for calculation of bank profits
        profit+= -balance*pow((1+loanint),time);
        balance -= -balance*pow((1+loanint),time);
    }
}

int getBalance(){
    return balance;
}
void moveTime(int days){
    time = days;
}
void setRate(double dailyrate){
    interest = dailyrate;
}
//Having trouble accessing bank information to determine if profit is great enough
//for withdrawal.
bool withdraw(double amount){
    if(open){
        if(amount>balance){
            return false;
        }
        if(balance>amount){
            balance-=amount;
            return true;
        }
    }
    else if (!open){
        return false;
    }
}
void makeDeposit(double amount){
    balance+=amount;
}
double close(){
    return balance;
    open = false;
}
int getBankId(){
    return BankId;
}
void transferTo(BankAccount destination, double money){
    balance-=money;
    destination.balance+=money;
}


private:

};

class Bank{
public:
    int BankId;
    double profitBank;
    vector<BankAccount> BankAccounts;

Bank(){
    BankId=numBanks;
    numBanks++;
    profitBank = 0;
}


int getBankId(){
    return BankId;
}
void Account(BankAccount acc){
    BankAccounts.push_back(acc);
    acc.accnum = BankAccounts.size();
}
double getProfit(){
    for (int i=0; i<BankAccounts.size(); i++){
        if(BankAccounts[i].balance>0){
            profitBank += BankAccounts[i].profit;
        }
        if(BankAccounts[i].balance<0){
            profitBank += BankAccounts[i].profit;
        }
    }

    return profitBank;
}

void printBankAccounts(){
    for (int j=0; j<BankAccounts.size(); j++){
        cout<<"Acc Num: "<<BankAccounts[j].accnum<<" Balance: "<<BankAccounts[j].balance;
        if (BankAccounts[j].open){
            cout<<" Status: "<<"open."<<endl;
        }
        else {
            cout<<"Status: "<<"closed."<<endl;
        }
    }
}
private:
int numBanks=0;



};



int main()
{
    Bank citizen, BoA;
    BankAccount Checking(1000, .02, BoA.getBankId());
    BoA.Account(Checking);
    Checking.moveTime(20);
    cout<<Checking.getBalance()<<endl;
    cout<<BoA.getProfit()<<endl;
    BoA.printBankAccounts();
    cout<<Checking.withdraw(1000)<<endl;
    cout<<"Checking Balance: "<<Checking.getBalance()<<endl;
    BankAccount Loan(-2000, .1, citizen.getBankId());
    Checking.transferTo(Loan, 1000);
    cout<<"New Checking Balance: "<<Checking.getBalance()<<" New Loan Balance: "<<Loan.getBalance()<<endl;

    citizen.Account(Loan);
    Loan.moveTime(30);
    cout<<Loan.getBalance()<<endl;
    cout<<citizen.getProfit()<<endl;
    cout<<citizen.getBankId()<<endl;

    return 0;
}
