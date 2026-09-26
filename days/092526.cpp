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
            hp > 0; 
            maxHP >= 1;
            hp <= maxHP; 
            potions > 0; 
            gold > 0; 
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
                std::cout << name << " total HP: " << health << " / " << maxHealth << '\n';
                health += 30; 
                if (health > maxHealth) { 
                    health = maxHealth; 
                }

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
                std::cout << "Invalid amount of gold." << '\n';
            }
        }

        void spendGold(int amount) { 
            if (amount <= gold) {
                std::cout << name << " spent " << amount << " gold!" << '\n';
                gold -= amount; 
                std::cout << "Total gold: " << gold << '\n';
            }
            else if (amount < 0) { 
                std::cout << "Invalid amount of gold." << '\n';
            }

            else {
                std::cout << "Not enough gold." << '\n';
            }
        }


    };

int main() {
    Adventurer hero ("Blake", 100, 100, 2, 30); 
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
    hero.gainGold(-100000000); f
    hero.spendGold(-10000000); 
    hero.spendGold(1999990); 
    hero.spendGold(100); 
    return 0; 
}
