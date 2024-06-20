#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;
    string accountNumber;
    string accountHolderName;

public:
    BankAccount(string accNum, string accHolder, double initBalance) 
        : accountNumber(accNum), accountHolderName(accHolder), balance(initBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid withdraw amount or insufficient balance." << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account("123456789", "John Doe", 500.0);
    account.deposit(150.0);
    account.withdraw(100.0);
    cout << "Final Balance: " << account.getBalance() << endl;

    return 0;
}
