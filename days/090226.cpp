#include <iostream>
int accBalance = 1000; 
void displayBalance() { 
    std::cout << "Your balance is: " << accBalance << '\n';
}

void depositMoney() {
    int depositAmount; 
    std::cout << "How much would you like to deposit? " << '\n';
    std::cin >> depositAmount;

    if (depositAmount < 0 || depositAmount == 0) {
        std::cout << "Deposit amount invalid." << '\n'; 
        std::cout << "How much would you like to deposit? " << '\n';
        std::cin >> depositAmount;
    }
    
    else { 
        accBalance += depositAmount; 
        std::cout << "$" << depositAmount << " deposited successfully." << '\n'; 
    }
}

void withdrawMoney() {
    int withdrawAmount; 
    std::cout << "How much would you like to withdraw? " << '\n';
    std::cin >> withdrawAmount;

    if (withdrawAmount < 0 || withdrawAmount == 0 || withdrawAmount > accBalance) {
        std::cout << "Withdraw amount invalid." << '\n'; 
        std::cout << "How much would you like to withdraw? " << '\n';
        std::cin >> withdrawAmount;
    }
    
    else { 
        accBalance -= withdrawAmount; 
        std::cout << "$" << withdrawAmount << " withdrawn successfully." << '\n'; 
    }

}

void displayMenu() {
    bool enterLoop = true; 
    int userInput; 
    while(enterLoop) { 
        std::cout << "1. Check balance" << '\n'; 
        std::cout << "2. Deposit money" << '\n'; 
        std::cout << "3. Withdraw money" << '\n'; 
        std::cout << "4. Exit" << '\n'; 
        std::cin >> userInput; 

        switch(userInput) {
            case 1: 
                displayBalance(); 
                break; 
            case 2: 
                depositMoney(); 
                break;
            case 3:
                withdrawMoney(); 
                break;
            case 4: 
                enterLoop = false; 
        }
    }

    std::cout << "Goodbye!" << '\n'; 


}

int main() {
    displayMenu(); 
    return 0; 
}
