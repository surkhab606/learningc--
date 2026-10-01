#include <vector> 
#include <iostream> 
#include <string> 

class Item { 
    private: 
        std::string name;
        int gold;
    
    public: 
        Item(std::string itemName, int itemGoldValue) : name(itemName), gold(itemGoldValue) {
            if (gold < 0) {
                gold = 0; 
            }
        }

        std::string getName() const {
            return name; 
        }

        int getGold() const { 
            return gold; 
        }

};

class Adventurer {
    private:
        std::string name;
        int gold;
        std::vector<Item> inventory; 
    
    
    public: 
        Adventurer(std::string adventurerName, int adventurerGold, std::vector<Item> adventuerInventory) : 
        name(adventurerName), gold(adventurerGold), inventory(adventuerInventory) {
            if (gold < 0) {
                gold = 0; 
            }
        }

        void findItem() {  
                Item userItem {"", 0}; 
                int userChoice = 0; 
                std::cout << "Select a random number between 1-6 to get a random item!" << '\n';
                std::cin >> userChoice; 

                while (std::cin.fail() || userChoice < 1 || userChoice > 6) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n'); 
                    std::cout << "Please enter a valid number (1-6)." << '\n';
                    std::cin >> userChoice;
                }

                switch (userChoice) {
                    case 1:
                        userItem = {"{Common} Unreliable Torch", 1};
                        std::cout << "You got..." << '\n';
                        std::cout << "A " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        break;
                    case 2:
                        userItem = {"{MYTHICAL} Sword of Righteousness", 500};
                        std::cout << "You got..." << '\n';
                        std::cout << "The " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        break;
                    case 3:
                        userItem = {"{Common} Broken Axe", 5};
                        std::cout << "You got..." << '\n';
                        std::cout << "A " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        break;
                    case 4:
                        userItem = {"{Rare} Elixir of Life", 25};
                        std::cout << "You got..." << '\n';
                        std::cout << "The " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        break;
                    case 5:
                        userItem = {"{Uncommon} Cup of Water", 10};
                        std::cout << "You got..." << '\n';
                        std::cout << "A " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        break; 
                    case 6:
                        userItem = {"{Uncommon} Foregone Traveler's Sword", 15};
                        std::cout << "You got..." << '\n';
                        std::cout << "The " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        break;
                }

                inventory.push_back(userItem); 
            }

        void viewInventory() const { 
            if (inventory.empty() == true) { 
                std::cout << "Nothing in inventory." << '\n';
            }

            else { 
                std::cout << " === INVENTORY === " << '\n'; 
                int iterator = 1; 
                for (const Item& item : inventory) { 
                    std::cout << iterator << ". " << item.getName() << " - " << item.getGold() << " gold" << '\n';
                    iterator += 1;
                }
            }
            
        }

        void inspectItem() { 
            if (inventory.empty() == true) { 
                std::cout << "Inventory is empty." << '\n';
                return; 
            }
            int userChoice = 0; 
            viewInventory(); 
            std::cout << "Which item would you like to inspect? " << '\n';
            std::cin >> userChoice; 
            
            while (std::cin.fail() || userChoice < 1 || userChoice > inventory.size() + 1) {
                std::cin.clear();
                std::cin.ignore(10000, '\n'); 
                std::cout << "Choose a valid item option." << '\n';
            }

            std::cout << "Inspecting " << inventory[userChoice - 1].getName() << '\n';
            std::cout << "Value: " << inventory[userChoice - 1].getGold() << '\n';
        }

        void sellLastItem() { 
            if (inventory.empty() == true) {
                std::cout << "Nothing to sell." << '\n';

            }

            else {
                Item lastItem = inventory.back(); 
                int value = lastItem.getGold();  
                std::cout << "Sold " << lastItem.getName() << " for " << value << " gold" << '\n';
                gold += value; 
                inventory.pop_back();
                std::cout << "Total gold: " << gold << '\n';
            }
        }


};


void openInventory(Adventurer& hero) { 
    int userChoice = 0; 
    while (userChoice != 5) {
        std::cout << " === INVENTORY SYSTEM ===" << '\n';
        std::cout << "1. Find Item " << '\n';
        std::cout << "2. View Inventory " << '\n';
        std::cout << "3. Inspect Item " << '\n';
        std::cout << "4. Sell Last Item " << '\n';
        std::cout << "5. Leave " << '\n';
        std::cin >> userChoice;

        while (std::cin.fail() || userChoice < 1 || userChoice > 5) {
            std::cin.clear();
            std::cin.ignore(10000, '\n'); 
            std::cout << "Invalid menu option. Select a valid option." << '\n';
            std::cin >> userChoice;
        }

        switch(userChoice) {
            case 1:
                hero.findItem(); 
                break;
            case 2:
                hero.viewInventory();
                break;
            case 3: 
                hero.inspectItem();
                break;
            case 4:
                hero.sellLastItem();
                break;
            case 5: 
                break;
        }
    }

    std::cout << "Closing inventory..." << '\n';
    std::cout << "Inventory closed." << '\n';
}

int main() { 
    Adventurer hero {"Blake", 30, {}};
    openInventory(hero); 
    
    return 0;
}
