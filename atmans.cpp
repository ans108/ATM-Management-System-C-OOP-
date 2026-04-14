#include <cstdio>
#include <iostream>
#include <memory>
#include <sec_api/stdio_s.h>
#include <system_error>
using namespace std;
class atm{
    private:
    double balance;
    public:
    void setbalance(double b){
        balance =b;
    }
    double getbalance(){
        return balance;
    }
    double withdraw(double amount){
        if (amount>balance) {
        return false;
        }
        balance=balance-amount;
        return true;
    }
    void deposit(double amount){
        balance+=amount;
    }
};
int main(){
    atm a;
    a.setbalance(200);
int choice;
double amount,balance;
char op;
do{
    system("cls");
    printf("1 view balance ");
    printf("\n2 cash withdraw ");
    printf("\n3 cash deposit");
    printf("\n4 exit");
    printf("\nenter you choice");
    cin >>choice;
    switch(choice){
        case 1:
        printf("your balance is:%f",a.getbalance());
        break;
        case 2:
        printf("enter the amount to withdraw");
        cin>>amount;
        if (cin.fail()) {
            printf("\ninvalid input");
        break;
        }
        if (a.withdraw(amount)) {
        printf("cash withdraw suuccessfully \n your remaing balance is:%f",a.getbalance());
        }
        else {
        printf("you dont have enough money");
        }
        break;
        case 3:
        printf("enter the amount");
        cin>>amount;
        if (cin.fail()) {
            printf("\ninvalid input");
        break;
        }
        a.deposit(amount);
        printf(" deposit suceefully\nyour total balance is:%f",a.getbalance());
        break;
        case 4:
        printf("program end");
        break;
        default:
        printf("invalid choice");


    }
    printf("\ndo u want another press y if no press any key");
    cin>>op;
}while(op=='y'||op=='Y');


}
