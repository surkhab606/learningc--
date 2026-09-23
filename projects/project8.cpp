// SEP. 13 2026

#include <iostream>

void playerAttack(int& health, int& gobHealth) {

    std::cout << "Player deals 15 damage to the Goblin! " <<  '\n';
    gobHealth -= 15;

    if (gobHealth >= 1) {
        std::cout << "Goblin retaliates and deals 10 damage to the Player!" << '\n';
        health -= 10; 
    }

    else {
        std::cout << "The goblin has died..." << '\n';
        gobHealth = 0; 

    }
    


}

void drinkPotion(int& health, int& potions) {
    if (potions < 1) {
        std::cout << "You have no potions." << '\n';
    }
    
    else {
        potions -= 1;
        std::cout << "You drank one potion." << '\n';
        if (health <= 70) {
            health += 30;
        }
        else {
            health = 100; 
        }
    }
}

void viewStatus(int health, int potions, int gobHealth) {
    std::cout << "Player HP: " << health << " / 100" << '\n';
    std::cout << "Potions: " << potions << '\n';
    std::cout << "Goblin HP: " << gobHealth << '\n';

}
void enterBattle (int playerHealth, int playerPotionCount, int goblinHealth) {
    int userChoice = 0; 
    while (userChoice != 4 && playerHealth > 0 && goblinHealth > 0) {
        std::cout << " === GOBLIN BATTLE === " << '\n';
        std::cout << "1. Attack " << '\n'; 
        std::cout << "2. Drink Potion " << '\n'; 
        std::cout << "3. View Status" << '\n'; 
        std::cout << "4. Run Away " << '\n'; 
        std::cin >> userChoice; 

        while (std::cin.fail() || userChoice < 1 || userChoice > 4) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a valid menu option." << '\n';
            std::cin >> userChoice;
        }

        switch(userChoice) {
            case 1: 
                playerAttack(playerHealth, goblinHealth);
                break;
            case 2:
                drinkPotion(playerHealth, playerPotionCount);
                break;
            case 3: 
                viewStatus(playerHealth, playerPotionCount, goblinHealth);
                break;
        }
    }

    std::cout << "You barely got away..." << '\n';
}


int main() { 
    enterBattle(100, 2, 60); 
    return 0; 
}
