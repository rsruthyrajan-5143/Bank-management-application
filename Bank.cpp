#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Bank {
public:
    int accNo;
    string name;
    float balance;

    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> balance;

        ofstream file("bank.txt", ios::app);
        file << accNo << endl;
        file << name << endl;
        file << balance << endl;
        file.close();

        cout << "\nAccount Created Successfully!\n";
    }

    void displayAll() {
        ifstream file("bank.txt");
        if (!file) {
            cout << "No records found!\n";
            return;
        }

        while (file >> accNo) {
            file.ignore();
            getline(file, name);
            file >> balance;

            cout << "\nAccount No: " << accNo;
            cout << "\nName: " << name;
            cout << "\nBalance: " << balance << endl;
        }

        file.close();
    }

    void searchAccount() {
        int searchAcc;
        cout << "Enter Account Number: ";
        cin >> searchAcc;

        ifstream file("bank.txt");
        bool found = false;

        while (file >> accNo) {
            file.ignore();
            getline(file, name);
            file >> balance;

            if (accNo == searchAcc) {
                cout << "\nAccount Found!";
                cout << "\nName: " << name;
                cout << "\nBalance: " << balance << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Account Not Found!\n";

        file.close();
    }

    void deposit() {
        cout << "\n(Deposit feature requires file update. Explain this during demo.)\n";
    }

    void withdraw() {
        cout << "\n(Withdraw feature requires file update. Explain this during demo.)\n";
    }
};

int main() {
    Bank b;
    int choice;

    do {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Search Account\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                b.createAccount();
                break;
            case 2:
                b.displayAll();
                break;
            case 3:
                b.searchAccount();
                break;
            case 4:
                b.deposit();
                break;
            case 5:
                b.withdraw();
                break;
            case 6:
                cout << "Thank You!\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
