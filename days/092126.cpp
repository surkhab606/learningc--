#include <iostream>
#include <string> 

struct Player { 
    std::string name; 
    int health;
    int maxHealth;
    int potions;
    int damage;

    bool drinksPotion(int& potions, int& health, int maxHealth) {
        if (potions >= 1) {
            std::cout << "You drank a potion. Restored 30 HP. " << '\n'; 
            potions -=1; 
            health += 30; 

            if (health > maxHealth) {
                health = maxHealth;
            }
            return true; 
        }

        else {
            std::cout << "You do not have any potions." << '\n';
            return false; 
        }
    }

    void takesDamage(std::string name, int& health, int& damage) {
        std::cout << name << " took " << damage << " damage!" << '\n'; 
        health -= damage; 
        return; 
    }
};

struct Enemy { 
    std::string name; 
    int health;
    int maxHealth;
    int damage;

    void takesDamage(std::string name, int& health, int& damage) {
        std::cout << name << " took " << damage << " damage!" << '\n'; 
        health -= damage; 
        return; 
    }
};

void enemyAttack(Player& player, Enemy& enemy) { 
    std::cout << enemy.name << " deals " << enemy.damage << " damage!" << '\n'; 
    player.takesDamage(player.name, player.health, enemy.damage); 
    if (player.health <= 0) {
        return; 
    }

}

void playerAttack (Player& player, Enemy& enemy) { 
    std::cout << player.name << " deals " << player.damage << " damage!" << '\n'; 
    enemy.takesDamage(enemy.name, enemy.health, player.damage); 
    if (enemy.health <= 0) {
        return;
    }

    else {
        enemyAttack(player, enemy); 
    }
}

void viewStatus(const Player& player, const Enemy& enemy) {
    std::cout << player.name << '\n';
    std::cout << "HP: " << player.health << " / " << player.maxHealth << '\n'; 
    std::cout << "Potions: " << player.potions << '\n';
    std::cout << "Damage: " << player.damage << '\n'; 
    std::cout << " " << '\n';
    std::cout << enemy.name << '\n';
    std::cout << "HP: " << enemy.health << " / " << enemy.maxHealth << '\n'; 
    std::cout << "Damage: " << enemy.damage << '\n'; 

}



void orcEncounter(Player& player, Enemy& enemy) { 
    int userChoice = 0;
    bool potionAttempt; 
    while (userChoice != 4 && player.health > 0 && enemy.health > 0) {
        std::cout << "=== ORC ENCOUNTER ===" << '\n'; 
        std::cout << " " << '\n';
        std::cout << "1. Attack" << '\n';
        std::cout << "2. Drink Potion" << '\n';
        std::cout << "3. View Status" << '\n';
        std::cout << "4. Flee" << '\n';
        std::cin >> userChoice;

        while (std::cin.fail() || userChoice < 1 || userChoice > 4) {
            std::cin.clear();
            std::cin.ignore(10000, '\n'); 
            std::cout << "Please enter a valid menu option." << '\n';
            std::cin >> userChoice; 
        }

        switch(userChoice) { 
            case 1: 
                playerAttack(player, enemy); 
                break;
            case 2:
                potionAttempt = player.drinksPotion(player.potions, player.health, player.maxHealth);
                if (potionAttempt == true) { 
                    enemyAttack(player, enemy); 
                }
                break;
            case 3:
                viewStatus(player, enemy); 
                break;
            case 4:
                break;
        }

    }

    if (player.health <= 0) {
        std::cout << player.name << " died..." << '\n';
    }

    if (enemy.health <= 0) {
        std::cout << enemy.name << " was defeated!" << '\n'; 
    }

    else if (enemy.health > 0 && player.health > 0) { 
        std::cout << "You barely got away..." << '\n'; 
    }
}

int main() { 
    Player knight {"Knight", 90, 100, 2, 20}; 
    Enemy orc {"Orc", 75, 75, 13}; 
    orcEncounter(knight, orc); 
    
    return 0; 
}
