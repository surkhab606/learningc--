#include <iostream>
bool skelAlive(int skelHP) {
    if (skelHP <= 0) {
        return false;
    }

    else {
        return true;
    }
}

void skeletonTurn(int& playerHP, int& skelHP) {
    playerHP -= 12; 
    std::cout << "Skeleton dealt 12 damage!" << '\n';
    if (playerHP < 1) {
        playerHP = 0;
        return;
    }
}

void normalAttack(int& playerHP, int& skelHP) {
    if (skelAlive(skelHP) == false) {
        return;
    }

    else { 
        skelHP -= 15; 
        std::cout << "Player dealt 15 damage!" << '\n';
        skeletonTurn(playerHP, skelHP); 
    }

}



void heavyAttack(int& playerHP, int& skelHP, int& attacksUsed) {
    if (attacksUsed % 2 == 0) {
        skelHP -= 30; 
        attacksUsed += 1;
        std::cout << "Player dealt 30 damage!" << '\n';
        if (skelAlive(skelHP) == false) {
            return; 
        }

        else {
            skeletonTurn(playerHP, skelHP); 
        }
    }

    else {
        std::cout << "Attack missed!" << '\n';
        attacksUsed += 1;
        skeletonTurn(playerHP, skelHP); 
    }
}

void drinkPotion(int& playerHP, int& potions, int& skelHealth) { 
    if (potions < 1) {
        std::cout << "No potions remaining." << '\n';
    }

    else {
        potions -= 1;
        playerHP += 25;
        if (playerHP > 100) {
            playerHP = 100; 
        } 
        std::cout << "Drank one potion... healed 25 HP." << '\n';
        skeletonTurn(playerHP, skelHealth); 
    }
}

void viewStatus (int& playerHP, int& skelHP, int& potions) {
    std::cout << "Player HP: " << playerHP << " / 100 " << '\n';
    std::cout << "Skeleton HP: " << skelHP << '\n';
    std::cout << "Potions: " << potions << '\n';
}

void enterMenu(int health, int potionCount, int skelHealth, int heavyAttacksUsed) {
    int userChoice = 0;
    bool skeletonAlive = true;
    bool playerAlive = true;
    while(userChoice != 5 && skeletonAlive && playerAlive) {
        std::cout << " === SKELETON DUEL === " << '\n'; 
        std::cout << "1. Attack" << '\n';
        std::cout << "2. Heavy Attack" << '\n';
        std::cout << "3. Drink Potion" << '\n';
        std::cout << "4. View Status" << '\n';
        std::cout << "5. Flee" << '\n';
        std::cin >> userChoice; 

        while(std::cin.fail() || userChoice < 1 || userChoice > 5) {
            std::cin.clear();
            std::cin.ignore(10000, '\n'); 
            std::cout << "Please enter a valid menu option." << '\n';
            std::cin >> userChoice;
        }

        switch(userChoice) {
            case 1:
                normalAttack(health, skelHealth); 
                if (skelAlive(skelHealth) == false) {
                    std::cout << "The skeleton died from your normal attack..." << '\n';
                    skeletonAlive = false;
                }

                if (health < 1) {
                    std::cout << "You were slain by the skeleton..." << '\n';
                    playerAlive = false;
                }
                break;
            case 2:
                heavyAttack(health, skelHealth, heavyAttacksUsed); 
                if (skelAlive(skelHealth) == false) {
                    std::cout << "The skeleton died from your heavy attack..." << '\n';
                    skeletonAlive = false;
                }

                if (health < 1) {
                    std::cout << "You were slain by the skeleton..." << '\n';
                    playerAlive = false;
                }
                break;
            case 3:
                drinkPotion(health, potionCount, skelHealth); 
                if (health < 1) {
                    std::cout << "You were slain by the skeleton..." << '\n';
                    playerAlive = false;
                }
                break;
            case 4:
                viewStatus(health, skelHealth, potionCount);
                break;
            case 5:
                std::cout << "You escaped from the battle." << '\n';
                break;
        }
    }
}

int main() { 
    enterMenu(10, 2, 70, 0);
    return 0; 
}
