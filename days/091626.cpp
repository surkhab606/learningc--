#include <iostream> 

struct Player { 
    int health;
    int maxHealth;
    int potions;
    int gold;
};

struct Enemy { 
    int health;
    int damage; 
};

void goblinAttack(Player& player, Enemy& enemy) {
    std::cout << "The goblin retaliated and dealt 12 damage to the player!" << '\n';
    player.health -= enemy.damage;
    if(player.health <= 0) {
        player.health = 0; 
        return;
    }   
}

void playerAttack(Player& player, Enemy& enemy) {
    std::cout << "Player dealt 18 damage to the goblin!" << '\n';
    enemy.health -= 18;
    if(enemy.health <= 0) {
        enemy.health = 0; 
        return;
    }

    else {
        goblinAttack(player, enemy);
    }

}

void drinkPotion(Player& player, Enemy& enemy) {
    if(player.potions > 0) {
        player.potions -= 1;
        std::cout << "Drank one potion. Restored 25 HP." << '\n';
        player.health += 25;
        if (player.health > player.maxHealth) {
            player.health = player.maxHealth; 
        }
        goblinAttack(player, enemy); 
    }

    else {
        std::cout << "Not enough potions." << '\n'; 
    }
}

void viewStatus(Player player, Enemy enemy) {
    std::cout << "Player HP: " << player.health << " / " << player.maxHealth << '\n';
    std::cout << "Player gold: " << player.gold << '\n';
    std::cout << "Player potions: " << player.potions << '\n';
    std::cout << "Enemy HP: " << enemy.health << '\n';

}

void bribeGoblin(Player& player, Enemy& enemy, bool& goblinBribed) {
    if (player.gold >= 5) { 
        player.gold -= 5; 
        std::cout << "You bribed the goblin and got away." << '\n';
        goblinBribed = true; 
        return;
    }

    else {
        std::cout << "Not enough gold." << '\n';
    }

}

void enterArena(Player& player, Enemy& enemy) { 
    int userChoice = 0; 
    bool bribed = false;
    while(userChoice != 5 && player.health > 0 && enemy.health > 0 && bribed == false) { 
        std::cout << " === GOBLIN ARENA === " << '\n'; 
        std::cout << "1. Attack" << '\n'; 
        std::cout << "2. Drink Potion" << '\n'; 
        std::cout << "3. View Status" << '\n'; 
        std::cout << "4. Bribe Goblin - 5 gold" << '\n'; 
        std::cout << "5. Flee" << '\n'; 
        std::cin >> userChoice; 

        while (std::cin.fail() || userChoice < 1 || userChoice > 5) { 
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
                drinkPotion(player, enemy); 
                break;
            case 3: 
                viewStatus(player, enemy);            
                break;
            case 4:
                bribeGoblin(player, enemy, bribed);
                break;
            case 5: 
                std::cout << "You barely got away!" << '\n';
                break;
        }
    }
    if (player.health == 0) {
        std::cout << "You died..." << '\n';
    }

    if (enemy.health == 0) {
        std::cout << "You defeated the goblin!" << '\n';
    }

}
int main() {
    
    
    Player hero {70, 100, 2, 10}; 
    Enemy goblin {50, 12}; 

    enterArena(hero, goblin);
    return 0; 
}
