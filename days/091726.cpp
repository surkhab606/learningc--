#include <iostream> 
#include <string> 

struct Player {
    std::string name; 
    int health; 
    int maxHealth;
    int potions;
    int damage;

};

struct Enemy { 
    std::string name; 
    int health; 
    int maxHealth;
    int damage;
};

void enemyAttack(Player& player, Enemy& enemy) {
    std::cout << enemy.name << " dealt " << enemy.damage << " damage to " << player.name << '\n';
    player.health -= enemy.damage;
    if (player.health <= 0) {
        player.health = 0;
        return;
    }
}

void attack(Player& player, Enemy& enemy) { 
    std::cout << player.name << " dealt " << player.damage << " damage to " << enemy.name << '\n';
    enemy.health -= player.damage;
    if (enemy.health <= 0) {
        enemy.health = 0;
        return;
    }
    else {
        enemyAttack(player, enemy); 
    }

}

void drinkPotion(Player& player, Enemy& enemy) {
    if(player.potions > 0) {
        std::cout << "Drank one potion. Restored 30 HP." << '\n';
        player.potions -= 1; 
        player.health += 30;
        if (player.health > player.maxHealth) {
            player.health = player.maxHealth;
        }

        enemyAttack(player, enemy); 
    }

    else {
        std::cout << "You don't have any potions remaining." << '\n';
    }
}

void viewStatus(const Player& player, const Enemy& enemy) {
    std::cout << player.name << " HP: " << player.health << " / " << player.maxHealth << '\n';
    std::cout << player.name << " Potions: " << player.potions << '\n';
    std::cout << player.name << " Damage: " << player.damage << '\n';
    
    std::cout << enemy.name << " HP: " << enemy.health << " / " << enemy.maxHealth << '\n';
    std::cout << enemy.name << " Damage: " << enemy.damage << '\n';
}

void enterArena(Player& player, Enemy& enemy) { 
    int userChoice = 0; 
    while(userChoice != 4 && player.health > 0 && enemy.health > 0) { 
        std::cout << " === MONSTER ARENA === " << '\n'; 
        std::cout << "1. Attack" << '\n';
        std::cout << "2. Drink Potion" << '\n';
        std::cout << "3. View Status" << '\n';
        std::cout << "4. Flee" << '\n';
        std::cin >> userChoice;

        while(std::cin.fail() || userChoice < 1 || userChoice > 4) { 
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            std::cout << "Please input a valid menu option." << '\n';
            std::cin >> userChoice;
        }

        switch(userChoice) {
            case 1:
                attack(player, enemy); 
                break;
            case 2:
                drinkPotion(player, enemy);
                break;
            case 3:
                viewStatus(player, enemy); 
                break;
            case 4:
                std::cout << "You barely got away..." << '\n';
                break;
        }
    }

    if (player.health == 0) {
        std::cout << player.name << " has died..." << '\n';
    }

    if (enemy.health == 0) {
        std::cout << "The  " << enemy.name << " has been slain..." << '\n';
    }

}




int main() { 
    Player hero {"Hero", 100, 100, 2, 18};
    Enemy skelly {"Skeleton", 65, 65, 11};
    enterArena(hero, skelly); 
    return 0; 
}
