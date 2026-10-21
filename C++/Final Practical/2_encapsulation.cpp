/*Define a class `BankAccount` with private attributes `accountNumber`, `balance`, and `ownerName`. Encapsulate these attributes 
using appropriate access specifiers. Implement public member functions to credit, debit, and display the balance. Demonstrate 
encapsulation by interacting with the class through its member functions.*/

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    int balance;
    string ownerName;

public:
    BankAccount(int a, int b, string n)
    {
        accountNumber = a;
        balance = b;
        ownerName = n;
    }

    void credit(int amount)
    {
        balance = balance + amount;
        cout << "Amount Credited: " << amount << endl;
    }

    void debit(int amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount Debited: " << amount << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void displayBalance()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount b1(101, 5000, "Mansvi");

    b1.displayBalance();

    b1.credit(2000);
    b1.debit(1000);

    cout << "\nFinal Account Details:" << endl;
    b1.displayBalance();

    return 0;
}

