#include <iostream>
void startBrewingMachine(int x); 

void checkIngredients(int ingredientsQuan) {
    std::cout << "There are " << ingredientsQuan << " ingredients available." << '\n';
    startBrewingMachine(ingredientsQuan); 
}


void brewPotion(int ingredientsQuantity) {
    int userSelection;
    if (ingredientsQuantity > 0) {
        std::cout << "How many ingredient units should I use? (1-3 per potion)" << '\n';
        std::cin >> userSelection; 
        
        while (std::cin.fail() || userSelection < 1 || userSelection > 3 || userSelection > ingredientsQuantity) { 
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            std::cout << "Enter a number from 1 to 3 that does not supersede the number of ingredients available." << '\n';
            std::cin >> userSelection;
        }

           ingredientsQuantity -= userSelection;
           std::cout << "Potion brewed successfully!" << '\n';

           startBrewingMachine(ingredientsQuantity);  
    }

    else {
        std::cout << "There are no more ingredients left. Sorry." << '\n';
    }

}

void startBrewingMachine(int numOfIngredients) {
    int userChoice; 
    std::cout << '\n';
    std::cout << "==== POTION BREWING MACHINE ====" << '\n'; 
    std::cout << "1. Brew potion" << '\n';
    std::cout << "2. Check ingredients" << '\n';
    std::cout << "3. Quit" << '\n';
    std::cin >> userChoice; 

    while (std::cin.fail() || userChoice < 1 || userChoice > 3) { 
        std::cin.clear(); 
        std::cin.ignore(10000, '\n'); 
        std::cout << "Enter a valid menu option." << '\n';
        std::cin >> userChoice;
    }

    if (userChoice == 1) {
        brewPotion(numOfIngredients); 
    }

    else if (userChoice == 2) {
        checkIngredients(numOfIngredients); 
    }

    else { 
         std::cout << "Goodbye!" << '\n';
    }


}

int main() {
    startBrewingMachine(10); 
    return 0;

}
