#include <iostream>

void drinkHealthPotion(int& playerPotions, int& playerHealth) {
    if (playerPotions < 1) {
        std::cout << "Not enough potions." << '\n';
    }

    else {
        playerPotions -= 1; 
        std::cout << "Drank one potion. HP restored." << '\n';

        if (playerHealth <= 75) {
            playerHealth += 25;
        }
        else { 
            playerHealth = 100; 
        }
    }
} 

void buyHealthPotion(int& playerPotions, int& playerGold) {
    std::cout << "Purchasing health potion..." << '\n';
    if(playerGold >= 5) {
        playerGold -= 5; 
        playerPotions += 1;
        std::cout << "Purchased 1 health potion." << '\n';
    }

    else {
        std::cout << "Not enough gold." << '\n';
    }
}

void takeDamage(int& playerHealth) {
    int damageAmount;
    std::cout << "How much damage? (1-30)" << '\n'; 
    std::cin >> damageAmount;
    
    while(std::cin.fail() || damageAmount < 1 || damageAmount > 30) {
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Please input a valid amount of damage. " << '\n';
        std::cin >> damageAmount; 
    }

    if (damageAmount >= playerHealth) {
        playerHealth = 0;
        std::cout << "Your adventurer has died." << '\n';
    }

    else {
        std::cout << "Took " << damageAmount << " damage. " << '\n';
        playerHealth -= damageAmount; 
        std::cout << "Health: " << playerHealth << '\n';
    }


} 

void viewStatus(int playerHealth, int playerMaxHealth, int playerPotions, int playerGold) {
    std::cout << "Health: " << playerHealth << " / " << playerMaxHealth << '\n';
    std::cout << "Potions: " << playerPotions << '\n'; 
    std::cout << "Gold: " << playerGold << '\n';
} 

void enterCamp(int health, int maxHealth, int potions, int gold) {
    int userChoice = 0;
    
    while(userChoice != 5) {
        std::cout << "====DUNGEON CAMP====" << '\n'; 
        std::cout << "1. Drink Health Potion" << '\n';    
        std::cout << "2. Buy Health Potion - 5 gold" << '\n';
        std::cout << "3. Take Damage" << '\n';
        std::cout << "4. View Status" << '\n';
        std::cout << "5. Leave Camp" << '\n';
        std::cin >> userChoice;

        while(std::cin.fail() || userChoice < 1 || userChoice > 5) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Please input a valid menu option. " << '\n';
            std::cin >> userChoice; 
        }

        switch(userChoice) {
            case 1: 
                drinkHealthPotion(potions, health); 
                break;
            case 2:
                buyHealthPotion(potions, gold);
                break;
            case 3: 
                takeDamage(health);
                if (health == 0) {
                    userChoice = 5; // i know this is crude but idk how to exit while loops from within nested statements... 
                }
                break;
            case 4: 
                viewStatus(health, maxHealth, potions, gold); 
                break;

        }
    }

    std::cout << "Goodbye." << '\n';
   
}

int main() {    
    enterCamp(60, 100, 3, 15); 
    return 0; 
}
