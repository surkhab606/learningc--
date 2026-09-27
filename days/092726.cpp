#include <iostream>
#include <string> 

class Adventurer {
    private:
        std::string name;
        int health;
        int maxHealth;
        int potions;
        int gold; 
    
    public: 
        Adventurer(std::string heroName, int hp, int maxHP, int potionCount, int goldCount)
        : name(heroName), health(hp), maxHealth(maxHP), potions(potionCount), gold(goldCount) {
            if (health < 0) {
                health = 0; 
            }

            if (maxHealth < 1) {
                maxHealth = 1; 
            }

            if (maxHealth > 100) {
                maxHealth = 100; 
            }

            if (health > maxHealth) {
                health = maxHealth;
            }

            if (potions < 0) {
                potions = 0; 
            }

            if (gold < 0) {
                gold = 0; 
            }

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

        int getGold() const {
            return gold;
        }

        bool isAlive() const { 
            if (health > 0) {
                return true; 
            }
            
            else {
                return false; 
            }
        }

        void takeDamage(int amount) { 
            if (amount >= 0) {
                std::cout << name << " took " << amount << " damage!" << '\n';
                health -= amount;
                if (health < 0) {
                    health = 0; 

                }
            }

            else { 
                std::cout << "Invalid damage amount." << '\n';
            }
            
        }

        void drinkPotion() {
            if (potions >= 1) {
                potions -= 1;
                std::cout << "Drank one potion. Restored 30 HP." << '\n'; 
                health += 30; 
                if (health > maxHealth) { 
                    health = maxHealth; 
                }
                std::cout << name << " total HP: " << health << " / " << maxHealth << '\n';

            }

            else { 
                std::cout << "No potions available." << '\n';
            }
        }

        void gainGold(int amount) { 
            if (amount >= 0) {
                std::cout << name << " gained " << amount << " gold!" << '\n';
                gold += amount; 
                std::cout << "Total gold: " << gold << '\n';
            }
            else {
                std::cout << "Invalid amount of gold to be gained." << '\n';
            }
        }

        bool spendGold(int amount) { 
            if (amount < 0) {
                std::cout << "Cannot spend " << amount << " gold. Invalid amount." <<'\n';
                return false;
            }
            else if (gold < amount) {
                std::cout << "Insufficient funds." << '\n';
                return false;
            }

            else {
                gold -= amount;
                std::cout << "Spent " << amount << " gold. " << gold << " gold remaining. " <<'\n';
                return true; 
            }

        }


    };

int main() {
    Adventurer hero ("BrokenHero", 900, -20, -5, -100); 
    std::cout << hero.getName() << '\n';
    std::cout << hero.getHealth() << '\n'; 
    std::cout << hero.getMaxHealth() << '\n';
    std::cout << hero.getPotionCount() << '\n';
    std::cout << hero.getGold() << '\n'; 
    std::cout << hero.isAlive() << '\n'; 
    hero.takeDamage(30); 
    hero.takeDamage(-10032034); 
    hero.drinkPotion(); 
    hero.gainGold(1000); 
    hero.gainGold(-100000000); 
    hero.spendGold(-10000000); 
    hero.spendGold(1999990); 
    hero.spendGold(100); 
    return 0; 
}

