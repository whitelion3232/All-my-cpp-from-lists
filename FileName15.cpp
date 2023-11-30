#include <iostream>

class Account {
protected:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        balance -= amount;
    }

    virtual void displayBalance() const {
        std::cout << "Current Balance: $" << balance << std::endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate) : Account(initialBalance), interestRate(rate) {}

    void addInterest() {
        double interest = balance * interestRate;
        deposit(interest);
        std::cout << "Interest added: $" << interest << std::endl;
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(double initialBalance, double limit) : Account(initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
        }
        else {
            std::cout << "Withdrawal exceeds overdraft limit!" << std::endl;
        }
    }
};

int main() {
    Account* savings = new SavingsAccount(2000, 0.08);
    Account* checking = new CheckingAccount(300, 200);

    savings->deposit(500);
    savings->displayBalance();

    savings->withdraw(200);
    savings->displayBalance();

    static_cast<SavingsAccount*>(savings)->addInterest();
    savings->displayBalance();

    checking->withdraw(700);
    checking->displayBalance();

    delete savings;
    delete checking;

    return 0;
}
