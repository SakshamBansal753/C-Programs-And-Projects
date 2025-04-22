#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int balance;
    string name;
    int deposit;
    string mobile;
    string address;
    int withdraw;
    static string bankname;
    int creditLimit = 100000;
    
public:
    Employee() {
        bankname = "SBI";
        balance = 0;
        deposit = 0;
        mobile = "invalid";
        withdraw = 0;
    }
    friend class Credit;
    
    void display() {
        cout << "BANKNAME=" << bankname << endl;
    }
    
    void set_details() {
        cout << "\nEnter name: ";
        cin >> name;
        cout << "Enter Mobile no.: ";
        cin >> mobile;
        cout << "Enter city pin: ";
        cin >> address;
    }
    
    void set_details_menu() {
        int choice;
        while (true) {
            cout << "\nChoose an option:\n1) Deposit\n2) Withdraw\n3) Check Balance\n4) Fast Payment\n5) Exit\nOption: ";
            cin >> choice;
            
            if (choice == 5) break;
            
            switch (choice) {
                case 1:
                    cout << "Enter amount to deposit: ";
                    cin >> deposit;
                    balance += deposit;
                    check(creditLimit);
                    break;
                case 2:
                    cout << "Enter amount to withdraw: ";
                    cin >> withdraw;
                    if (withdraw > balance) {
                        cout << "Insufficient balance!\n";
                    } else {
                        balance -= withdraw;
                        check(creditLimit);
                    }
                    break;
                case 3:
                    cout << "Current balance: " << balance << endl;
                    break;
                case 4:
                    fastPayment();
                    break;
                default:
                    cout << "Invalid choice, try again.\n";
            }
        }
    }
    
    void fastPayment() {
        int amount;
        string recipient;
        cout << "Enter recipient name: ";
        cin >> recipient;
        cout << "Enter amount: ";
        cin >> amount;
        
        if (amount > balance) {
            cout << "Insufficient funds for payment!\n";
        } else {
            balance -= amount;
            cout << "Payment of " << amount << " to " << recipient << " successful!\n";
            check(creditLimit);
        }
    }
    void getdetails() {
        cout << "\nName: " << name << "\nAddress: " << address << "\nMobile: " << mobile << endl;
    }
    int bal() {
        return balance;
    }
    int limit() {
        return creditLimit;
    }
    
    void check(int creditLimit) {
        if (balance < -creditLimit) {
            cout << "Error: Credit limit exceeded!\n";
            balance += deposit - withdraw;
        } else {
            cout << "Transaction successful. Current balance: " << balance << endl;
        }
    }
};

string Employee::bankname = "SBI";

class Credit {
public:
    void check(Employee &emp) {
        int currentBalance = emp.bal();
        int creditLimit = emp.limit();
        
        if (currentBalance < -creditLimit) {
            cout << "Credit limit exceeded! Current balance: " << currentBalance << endl;
        } else {
            cout << "Within credit limit. Current balance: " << currentBalance << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    Employee E[n];
    E[0].display();
    
    for (int i = 0; i < n; i++) {
        E[i].set_details();
        E[i].set_details_menu();
    }
    
    cout << "\nIf you want to see complete details, type 1: ";
    int m;
    cin >> m;
    if (m == 1) {
        for (int i = 0; i < n; i++) {
            E[i].getdetails();
        }
    }
    
    Credit f;
    for (int i = 0; i < n; i++) {
        f.check(E[i]);  
    }
    
    return 0;
}
