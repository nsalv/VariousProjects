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
    time = 0;

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

void makeDeposit(double amount){
    balance+=amount;
}
double close(){
    open = false;
    return balance;
}
int getBankId(){
    return BankId;
}
void transferTo(BankAccount destination, double money){
    balance-=money;
    destination.balance += money;
}
//define function after bank vector has been declared
bool withdraw(double amount);

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
vector<Bank> Banks;

bool BankAccount::withdraw(double amount){
    if(open){
        if(amount>balance || Banks[BankId].profitBank<amount){
            return false;
        }
        if(balance>amount && Banks[BankId].profitBank>amount){
            balance-=amount;
            return true;
        }
    }
    else if (!open){
        return false;
    }
}


int main()
{
    Bank citizen, BoA;
    Banks.push_back(citizen);
    Banks.push_back(BoA);

    BankAccount Checking(4000, .02, BoA.getBankId());
    //Is adding interest before moveTime function...
    cout<<"Initial Checking balance: "<<Checking.getBalance()<<endl;

    BoA.Account(Checking);
    Checking.moveTime(20);
    cout<<"BoA earnings after 20 days: "<<BoA.getProfit()<<endl;

    //cannot withdraw money unless Bank can cover it.
    cout<<"Attempt to withdraw 500 dollars from Checking: ";
    if (!Checking.withdraw(500)){
        cout<<"failed."<<endl;
    }
    else if (Checking.withdraw(500)){
        cout<<" success."<<endl;
    }
    BoA.printBankAccounts();

    cout<<"Checking Balance: "<<Checking.getBalance()<<endl;
    BankAccount Loan(-2000, .1, citizen.getBankId());
    Checking.transferTo(Loan, 1000);

    //Money isn't being added to Loan for some reason.
    cout<<"New Checking Balance: "<<Checking.getBalance()<<" New Loan Balance: "<<Loan.getBalance()<<endl;


    cout<<"Closed Checking Account. Money in account: "<<Checking.close()<<endl;
    //Withdraw will not function with a closed account
    cout<<Checking.withdraw(1000)<<endl;

    citizen.Account(Loan);

    citizen.printBankAccounts();
    Loan.moveTime(30);
    cout<<"Loan Balance after 30 days: "<<Loan.getBalance()<<endl;
    cout<<"Citizen bank's profit after 30 days: "<<citizen.getProfit()<<endl;
    cout<<"Citizen Bank Id: "<<citizen.getBankId()<<endl;



    return 0;
}
