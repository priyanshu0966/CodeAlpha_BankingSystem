#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    Transaction(string t, double a) : type(t), amount(a) {}
};

class Account {
private:
    double balance;
    vector<Transaction> history;
public:
    Account(double initial) : balance(initial) {}
    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Deposited: " << amount << "\n";
    }
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds.\n";
            return;
        }
        balance -= amount;
        history.push_back(Transaction("Withdraw", amount));
        cout << "Withdrew: " << amount << "\n";
    }
    void showBalance() const {
        cout << "Current Balance: " << balance << "\n";
    }
    void showHistory() const {
        cout << "\nTransaction History:\n";
        for (auto &t : history) {
            cout << t.type << ": " << t.amount << "\n";
        }
    }
};

class Customer {
public:
    string name;
    Account account;
    Customer(string n, double initial) : name(n), account(initial) {}
};

int main() {
    Customer cust("John Doe", 1000.0);
    int choice;
    double amount;

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Show History\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter amount: ";
            cin >> amount;
            cust.account.deposit(amount);
            break;
        case 2:
            cout << "Enter amount: ";
            cin >> amount;
            cust.account.withdraw(amount);
            break;
        case 3:
            cust.account.showBalance();
            break;
        case 4:
            cust.account.showHistory();
            break;
        }
    } while (choice != 5);

    return 0;
}
