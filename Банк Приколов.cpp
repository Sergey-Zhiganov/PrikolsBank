#include <iostream>
using namespace std;

int main()
{
    
}
class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;
public:
    BankAccount(int newAccountNumber, double newBalance) {
        accountNumber = newAccountNumber;
        balance = newBalance;
        interestRate = 0.0;
    };
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "На счёт внесено " << amount << endl;
        }
        else {
            cout << "Неверная сумма";
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Со счёта снято " << amount << endl;
        }
        else {
            cout << "Недостаточно средств или введена неверная сумма";
        }
    }
    double getBalance() {
        return balance;
    }
    double getIntegest() {
        return balance * interestRate * (1.0 / 12.0);
    }
    int getAccountNumber() {
        return accountNumber;
    }
    void setInterestRate(double rate) {
        interestRate = rate;
    }
    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};
bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount > 0 && amount <= from.balance) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Успешно" << endl;
        return true;
    }
    else {
        cout << "Недостаточно средств или введена неверная сумма" << endl;
        return false;
    }
}
