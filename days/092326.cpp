#include <iostream>
#include <string> 

class Fighter {
    private: 
        std::string name; 
        int health;
        int maxHealth;
        int potions;
        int damage;

    public:
        Fighter(std::string fighterName, int hp, int maxHP, int potionCount, int dmg) {
            name = fighterName; 
            health = hp; 
            maxHealth = maxHP;
            potionCount = potions;
            damage = dmg;
        }

        std::string getName() const {
            return name;
        }

        int getHealth() const {
            return health;
        }

        int getMaxHealth() const {
            return maxHealth;
        }

        int getPotionCount() const {
            return potions;
        }

        int getDamage() const {
            return damage;
        }

        void takeDamage(int amount) { 
            health -= amount;
            if (health < 0) {
                health = 0; 
                return;
            }
        }

        bool drinksPotion() { 
            if (potions > 0) {
                potions -= 1;
                health += 30; 

                if (health > 100) {
                    health = 100; 
                }
                std::cout << "Drank one potion. Restored 30 HP." << '\n';
                return true;
            }

            else {
                std::cout << "No potions available." << '\n';
                return false;
            }
        }

        void viewStatus() const {
            std::cout << name << " HP: " << health << " / " << maxHealth << '\n';
            std::cout << name << " Potions: " << potions << '\n';
            std::cout << name << " Damage: " << damage << '\n';

        }   


};

void attack(Fighter& attacker, Fighter& enemy) { 
    enemy.takeDamage(attacker.getDamage()); 
    std::cout << attacker.getName() << " did " << attacker.getDamage() << " damage to " << enemy.getName() << "!" << '\n';


    if (enemy.getHealth() > 0) {
        attacker.takeDamage(enemy.getDamage()); 
        std::cout << enemy.getName() << " did " << enemy.getDamage() << " damage to " << attacker.getName() << "!" << '\n';

    }

    return; 
}


void enterDuel(Fighter& hero, Fighter& enemy) { 
    int userChoice = 0; 
    bool potionDrank = false;
    while (userChoice != 4 && hero.getHealth() != 0 && enemy.getHealth() != 0) {
        std::cout << " === FIGHTER DUEL === " << '\n';
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
                attack(hero, enemy); 
                break;
            case 2:
                potionDrank = hero.drinksPotion();
                if (potionDrank == true) { 
                    hero.takeDamage(enemy.getDamage()); 
                } 
                break;
            case 3: 
                hero.viewStatus();
                enemy.viewStatus(); 
                break;
            case 4:
                break; 
            }

        }

        if (hero.getHealth() == 0) {
            std::cout << "You were defeated..." << '\n';
        }

        if (enemy.getHealth() == 0) {
            std::cout << "The " << enemy.getName() << " was defeated!" << '\n';
        }
        if (hero.getHealth() != 0 && enemy.getHealth() != 0) {
            std::cout << "You barely got away..." << '\n';
        }
    }

int main() {
    Fighter knight ("Knight", 90, 100, 2, 17);
    Fighter orc ("Orc", 70, 70, 0, 13);

    enterDuel(knight, orc); 

    return 0;
}
