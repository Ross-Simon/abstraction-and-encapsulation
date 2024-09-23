//Simple Banking System (Eguia, Ross Simon S.)

#include <iostream>
#include <iomanip>
using namespace std;

// Abstract Class
class UserAccount {
private: 
    double savingsBalance; 
    double currentBalance; 

protected: 
    UserAccount(double savingsBalance = 0.0, double currentBalance = 0.0) : savingsBalance(savingsBalance), currentBalance(currentBalance) {} 

    // Setters
    void setSavingsBalance(double amount) {
        savingsBalance = amount;
    }

    void setCurrentBalance(double amount) {
        currentBalance = amount;
    }

public:
    virtual void depositSavings(double amount) = 0; 
    virtual void withdrawSavings(double amount) = 0; 
    virtual void depositCurrent(double amount) = 0; 
    virtual void withdrawCurrent(double amount) = 0; 

    // Getters
    double getSavingsBalance() const {
        return savingsBalance; 
    }
    
    double getCurrentBalance() const {
        return currentBalance; 
    }
};

// Derived Class
class SubMenus : public UserAccount {
public:
    SubMenus(double savingsBalance = 0.0, double currentBalance = 0.0) : UserAccount(savingsBalance, currentBalance) {}

    void depositSavings(double amount) override {
        if (amount > 0) {
            double savingsBalance = getSavingsBalance();
            savingsBalance += amount;
            setSavingsBalance(savingsBalance);  
            cout << "\nDeposited to savings: " << amount << endl;
            cout << endl; 
        }
    }
    
    void withdrawSavings(double amount) override {
        if (amount > 0) {
            double savingsBalance = getSavingsBalance();
            savingsBalance -= amount;
            setSavingsBalance(savingsBalance);  
            	
				if (getSavingsBalance() < 1000) {
            	cout << "\nInsufficient funds in savings to withdraw. You must have a maintaining balance of 1000.00" << endl;
            	savingsBalance = 1000;
            	setSavingsBalance(savingsBalance); // Use setter to update current balance
				}
        } 
			else {
        		double savingsBalance = getSavingsBalance();
            	savingsBalance -= amount;
            	setSavingsBalance(savingsBalance);  // Use setter to update the  savings balance
        		cout << "\nWithdrew from savings: " << amount << endl; 
            	cout << endl; 
        	}
    }
    
    void depositCurrent(double amount) override {
        if (amount > 0) {
            double currentBalance = getCurrentBalance();
            currentBalance += amount;
            setCurrentBalance(currentBalance);  // Use setter to update the current balance
            cout << "\nDeposited to current: " << amount << endl;
            cout << endl;     
        }
    }
    
    void withdrawCurrent(double amount) override {
        if (amount > 0 && amount <= getCurrentBalance()) {
            double currentBalance = getCurrentBalance();
            currentBalance -= amount;
            setCurrentBalance(currentBalance);  // Use setter to update the current balance
            cout << "\nWithdrew from current: " << amount << endl;
            cout << endl; 
        } else {
            cout << "\nInsufficient funds in current." << endl;
            cout << endl; 
        }
    }
};

int main() {
    int mainChoice, savingsChoice, currentChoice; 
    double depositAmount, withdrawAmount; 
    
    SubMenus s1(1000.0, 0.0); // Initial Account Balance (savings, current)

    do {
        cout << "\n------------------------------\n";
        cout << "    Simple Banking System\n"; 
        cout << "------------------------------\n";
        cout << "\n[Main Menu]\n"; 
        cout << "1 - Savings Account\n"; 
        cout << "2 - Current Account\n"; 
        cout << "3 - Exit\n\n";
        cout << "Kindly choose an option [1-3]: ";
        cin >> mainChoice;
        cout << endl; 
        
        switch (mainChoice) { 
            case 1: 
                do { 
                	system("cls");
                    cout << "\n------------------------------\n";
                    cout << "    Savings Account Menu\n"; 
                    cout << "------------------------------\n";
                    cout << "1 - Deposit\n";
                    cout << "2 - Withdraw\n"; 
                    cout << "3 - Check Balance\n"; 
                    cout << "4 - Back\n\n"; 
                    cout << "Kindly choose an option [1-4]: "; 
                    cin >> savingsChoice; 
                    
                    switch (savingsChoice) {
                        case 1:
                            cout << "\nEnter Savings Account Deposit: "; 
                            cin >> depositAmount;
                            s1.depositSavings(depositAmount);
							system("pause"); 
                            system("cls");  
                            break;
                            
                        case 2:
                            cout << "\nEnter Savings Account Withdrawal: "; 
                            cin >> withdrawAmount;
                            s1.withdrawSavings(withdrawAmount);
                            cout << endl; 
							system("pause"); 
                            system("cls");   
                            break;
                            
                        case 3:
                            cout << "\nSavings Balance: " << fixed << setprecision(2) << s1.getSavingsBalance() << endl;
                            cout << endl;
							system("pause"); 
                            system("cls");  
                            break;
                            
                        case 4:
                        	system("pause"); 
                        	system("cls"); 
                            break; 
                            
                        default:
                            cout << "\nInvalid Input. Please try again.\n";
							cin.clear();
							cin.ignore(1000, '\n');
	        				system("pause"); 
        					system("cls"); 
                    }
                } while (savingsChoice != 4);
            	break; 
                
            case 2: 
                do {
                	system("cls");
                    cout << "\n------------------------------\n";
                    cout << "    Current Account Menu\n"; 
                    cout << "------------------------------\n";
                    cout << "1 - Deposit\n";
                    cout << "2 - Withdraw\n"; 
                    cout << "3 - Check Balance\n"; 
                    cout << "4 - Back\n\n"; 
                    cout << "Kindly choose an option [1-4]: "; 
                    cin >> currentChoice; 
                    
                    switch (currentChoice) {
                        case 1:
                            cout << "\nEnter Current Account Deposit: "; 
                            cin >> depositAmount;
                            s1.depositCurrent(depositAmount);
							system("pause"); 
                            system("cls");   
                            break;
                            
                        case 2:
                            cout << "\nEnter Current Account Withdrawal: "; 
                            cin >> withdrawAmount;
                            s1.withdrawCurrent(withdrawAmount);
							system("pause"); 
                            system("cls");   
                            break;
                            
                        case 3:
                            cout << "\nCurrent Balance: " << fixed << setprecision(2) << s1.getCurrentBalance() << endl;
							system("pause"); 
                            system("cls");   
                            break;
                            
                        case 4:
                        	system("pause"); 
                        	system("cls"); 
                            break; 
                            
                        default: 
                            cout << "\nInvalid Input. Please try again.\n";
							cin.clear();
							cin.ignore(1000, '\n');
	        				system("pause"); 
        					system("cls");  
                    }
                } while (currentChoice != 4);
                break; 
                
            case 3: 
                cout << "Exiting...\n"; 
                system("pause"); 
				cout << "\nThank you for using the banking system!" << endl;
                break;
				
			case 4: 		
				break;  
                
            default: 
                cout << "Invalid Input. Please try again.\n";
				cin.clear();
				cin.ignore(1000, '\n');
	        	system("pause"); 
        		system("cls"); 
        } 
    } while (mainChoice != 3); 
    
    return 0;
}