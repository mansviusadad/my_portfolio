
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount()
    {
        accountNumber = 0;
        accountHolderName = "";
        balance = 0;
    }

    void setData()
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Account Holder Name: ";
        cin >> accountHolderName;

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }

    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
            cout << "Amount Deposited Successfully!" << endl;
        }
        else
        {
            cout << "Invalid Amount!" << endl;
        }
    }

    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount Withdrawn Successfully!" << endl;
        }
        else
        {
            cout << "Insufficient Balance or Invalid Amount!" << endl;
        }
    }

    virtual void displayAccountInfo()
    {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void calculateInterest()
    {
        cout << "Interest calculation is not available." << endl;
    }

    virtual ~BankAccount()
    {
    }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    void setSavingsData()
    {
        setData();

        cout << "Enter Interest Rate (%): ";
        cin >> interestRate;
    }

    void calculateInterest() override
    {
        double interest = getBalance() * interestRate / 100;

        cout << "Savings Interest: " << interest << endl;
    }

    void displayAccountInfo() override
    {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    void setCheckingData()
    {
        setData();

        cout << "Enter Overdraft Limit: ";
        cin >> overdraftLimit;
    }

    bool checkOverdraft(double amount)
    {
        return amount > getBalance() &&
               amount <= getBalance() + overdraftLimit;
    }

    void withdraw(double amount) override
    {
        if (amount <= 0)
        {
            cout << "Invalid Amount!" << endl;
        }
        else if (amount <= getBalance())
        {
            BankAccount::withdraw(amount);
        }
        else if (checkOverdraft(amount))
        {
            double availableBalance = getBalance();

            BankAccount::withdraw(availableBalance);
            deposit(availableBalance - amount);

            cout << "Overdraft Used Successfully!" << endl;
        }
        else
        {
            cout << "Overdraft Limit Exceeded!" << endl;
        }
    }

    void displayAccountInfo() override
    {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:
    void setFixedDepositData()
    {
        setData();

        cout << "Enter Term in Months: ";
        cin >> term;

        cout << "Enter Annual Interest Rate (%): ";
        cin >> interestRate;
    }

    void deposit(double amount) override
    {
        cout << "Additional deposits are not allowed in Fixed Deposit."
             << endl;
    }

    void withdraw(double amount) override
    {
        cout << "Withdrawal is not allowed before maturity." << endl;
    }

    void calculateInterest() override
    {
        double interest = getBalance() * interestRate / 100 * term / 12;

        cout << "Fixed Deposit Interest: " << interest << endl;
    }

    void displayAccountInfo() override
    {
        BankAccount::displayAccountInfo();
        cout << "Term: " << term << " months" << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main()
{
    BankAccount *accounts[100];
    int count = 0;
    int choice, type, i, accountNumber, found;
    double amount;

    do
    {
        cout << "\n===== BANKING MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Display All Accounts" << endl;
        cout << "3. Deposit Amount" << endl;
        cout << "4. Withdraw Amount" << endl;
        cout << "5. Calculate Interest" << endl;
        cout << "6. Search Account" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count >= 100)
            {
                cout << "Account List is Full!" << endl;
                break;
            }

            cout << "\n1. Savings Account" << endl;
            cout << "2. Checking Account" << endl;
            cout << "3. Fixed Deposit Account" << endl;
            cout << "Enter Account Type: ";
            cin >> type;

            if (type == 1)
            {
                SavingsAccount *s = new SavingsAccount;
                s->setSavingsData();
                accounts[count] = s;
                count++;
                cout << "Savings Account Created Successfully!" << endl;
            }
            else if (type == 2)
            {
                CheckingAccount *c = new CheckingAccount;
                c->setCheckingData();
                accounts[count] = c;
                count++;
                cout << "Checking Account Created Successfully!" << endl;
            }
            else if (type == 3)
            {
                FixedDepositAccount *f = new FixedDepositAccount;
                f->setFixedDepositData();
                accounts[count] = f;
                count++;
                cout << "Fixed Deposit Account Created Successfully!" << endl;
            }
            else
            {
                cout << "Invalid Account Type!" << endl;
            }
            break;

        case 2:
            if (count == 0)
            {
                cout << "No Accounts Found!" << endl;
            }
            else
            {
                for (i = 0; i < count; i++)
                {
                    cout << "\n------------------------" << endl;
                    accounts[i]->displayAccountInfo();
                }
            }
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accountNumber;

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (accounts[i]->getAccountNumber() == accountNumber)
                {
                    cout << "Enter Amount to Deposit: ";
                    cin >> amount;

                    accounts[i]->deposit(amount);
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                cout << "Account Not Found!" << endl;
            }
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accountNumber;

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (accounts[i]->getAccountNumber() == accountNumber)
                {
                    cout << "Enter Amount to Withdraw: ";
                    cin >> amount;

                    accounts[i]->withdraw(amount);
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                cout << "Account Not Found!" << endl;
            }
            break;

        case 5:
            cout << "Enter Account Number: ";
            cin >> accountNumber;

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (accounts[i]->getAccountNumber() == accountNumber)
                {
                    accounts[i]->calculateInterest();
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                cout << "Account Not Found!" << endl;
            }
            break;

        case 6:
            cout << "Enter Account Number: ";
            cin >> accountNumber;

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (accounts[i]->getAccountNumber() == accountNumber)
                {
                    accounts[i]->displayAccountInfo();
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                cout << "Account Not Found!" << endl;
            }
            break;

        case 7:
            for (i = 0; i < count; i++)
            {
                delete accounts[i];
            }

            count = 0;
            cout << "All Memory Freed Successfully!" << endl;
            cout << "Thank You!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}

