#include <iostream> 

int askFighterHealth() {
    int fighterHealth; 
    std::cout << "What is your fighter's health? (0-100)" << '\n'; 
    std::cin >> fighterHealth;
    
    while (fighterHealth < 1 || fighterHealth > 100) { 
        std::cout << "Invalid health inputted. Try again." << '\n';
        std::cin >> fighterHealth;
    }

    std::cout << "Your fighter's health is: " << fighterHealth << '\n';

    return fighterHealth;
}

int askNumOfHealthPotion() {
    int playerPotionNumber; 
    std::cout << "What is the number of health potions you would like? (0-5)" << '\n'; 
    std::cin >> playerPotionNumber;
    
    while (playerPotionNumber < 0 || playerPotionNumber > 5) { 
        std::cout << "Invalid number of potions inputted. Try again." << '\n';
        std::cin >> playerPotionNumber;
    }

    std::cout << "The number of potions you have chosen is: " << playerPotionNumber << '\n';

    return playerPotionNumber;
}

int askDifficulty() {
    int diff; 
    std::cout << "What difficulty would you like? (1. Easy, 2. Normal, 3. Hard)" << '\n';
    std::cin >> diff;

    while (diff < 1 || diff > 3) {
        std::cout << "Invalid difficulty chosen. Try again." << '\n';
        std::cin >> diff; 
    }

    std::cout << "You have chosen your difficulty." << '\n'; 

    return diff; 
}

void displayStats(int health, int potions, int chosenDiff) {
    std::cout << " " << '\n'; 
    std::cout << "====NEW FIGHTER IN THE ARENA...====" << '\n';
    std::cout << "Your player's health: " << health << '\n'; 
    std::cout << "Your player is carrying " << potions << " health potions" << '\n';
    
    switch(chosenDiff) {
        case 1: 
            std::cout << "Difficulty: Easy" << '\n'; 
            break;
        case 2:
            std::cout << "Difficulty: Normal" << '\n'; 
            break;
        case 3:
            std::cout << "Difficulty: Hard" << '\n'; 
            break;
        default:
            std::cout << "Difficulty: unknown_err_0" << '\n'; 


    }
}

int main() {
    int playerHealth = askFighterHealth(); 
    int playerPotions = askNumOfHealthPotion(); 
    int playerDifficulty = askDifficulty(); 

    displayStats(playerHealth, playerPotions, playerDifficulty);

    return 0; 
    
}
