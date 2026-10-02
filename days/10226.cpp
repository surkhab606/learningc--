#include <vector> 
#include <iostream> 
#include <string> 


// CODE COPIED FROM PREVIOUS DAY. 
// WE ONLY MADE MINOR CHANGES (ENUM CLASS RARITY)
enum class Rarity { 
    Unrated,
    Common,
    Uncommon,
    Rare,
    Mythical
}; 

class Item { 
    private: 
        std::string name;
        int gold;
        Rarity rarity; 
        
    
    public: 
        Item(std::string itemName, int itemGoldValue, Rarity itemRarity) : name(itemName), gold(itemGoldValue),rarity(itemRarity) {
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

        std::string rarityToString() const {
            switch(rarity) { 
                case Rarity::Common: 
                    return "Common"; 
                case Rarity::Uncommon: 
                    return "Uncommon";
                case Rarity::Rare: 
                    return "Rare";
                case Rarity::Mythical: 
                    return "Mythical";
            }

            return " ";
        }
};



class Adventurer {
    private:
        std::string name;
        int gold;
        std::vector<Item> inventory; 
    
    
    public: 
        Adventurer(std::string adventurerName, int adventurerGold, std::vector<Item> adventurerInventory) : 
        name(adventurerName), gold(adventurerGold), inventory(adventurerInventory) {
            if (gold < 0) {
                gold = 0; 
            }
        }

        void findItem() {  
                Item userItem {"", 0, Rarity::Unrated}; 
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
                        userItem = {"Unreliable Torch", 1, Rarity::Common}; 
                        std::cout << "You got..." << '\n';
                        std::cout << "A " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        std::cout << "Rarity: " << userItem.rarityToString() << '\n';
                        break;
                    case 2:
                        userItem = {"Sword of Righteousness", 500, Rarity::Mythical};
                        std::cout << "You got..." << '\n';
                        std::cout << "The " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        std::cout << "Rarity: " << userItem.rarityToString() << '\n';
                        break;
                    case 3:
                        userItem = {"Broken Axe", 5, Rarity::Common};
                        std::cout << "You got..." << '\n';
                        std::cout << "A " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        std::cout << "Rarity: " << userItem.rarityToString() << '\n';
                        break;
                    case 4:
                        userItem = {"Elixir of Life", 25, Rarity::Rare};
                        std::cout << "You got..." << '\n';
                        std::cout << "The " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        std::cout << "Rarity: " << userItem.rarityToString() << '\n';
                        break;
                    case 5:
                        userItem = {"Cup of Water", 10, Rarity::Uncommon};
                        std::cout << "You got..." << '\n';
                        std::cout << "A " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        std::cout << "Rarity: " << userItem.rarityToString() << '\n';
                        break; 
                    case 6:
                        userItem = {"Foregone Traveler's Sword", 15, Rarity::Common};
                        std::cout << "You got..." << '\n';
                        std::cout << "The " << userItem.getName() << '\n';
                        std::cout << "Value: " << userItem.getGold() << " gold " << '\n';
                        std::cout << "Rarity: " << userItem.rarityToString() << '\n';
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
                    std::cout << iterator << ". " << item.getName() << " - " << item.getGold() << " gold, " << item.rarityToString() << " rarity" << '\n';
                    iterator += 1;
                }
            }
            
        }

        void inspectItem() const { 
            if (inventory.empty() == true) { 
                std::cout << "Inventory is empty." << '\n';
                return; 
            }
            int userChoice = 0; 
            viewInventory(); 
            std::cout << "Which item would you like to inspect? " << '\n';
            std::cin >> userChoice; 
            
            while (std::cin.fail() || userChoice < 1 || userChoice > inventory.size()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n'); 
                std::cout << "Choose a valid item option." << '\n';
                std::cin >> userChoice;
            }

            std::cout << "Inspecting " << inventory[userChoice - 1].getName() << '\n';
            std::cout << "Value: " << inventory[userChoice - 1].getGold() << '\n';
            std::cout << "Rarity: " << inventory[userChoice - 1].rarityToString() << '\n';
        }

        void dropItem() { 
            if (inventory.empty() == true) {
                std::cout << "Nothing to drop." << '\n';
                return;
            }
            int userChoice = 0; 
            viewInventory(); 
            std::cout << "Which item would you like to drop? " << '\n';
            std::cin >> userChoice; 
            
            while (std::cin.fail() || userChoice < 1 || userChoice > inventory.size()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n'); 
                std::cout << "Choose a valid item option." << '\n';
                std::cin >> userChoice;
            }

            std::cout << "Dropping " << inventory[userChoice - 1].rarityToString() << " " << inventory[userChoice - 1].getName() << "... " << '\n';
            inventory.erase(inventory.begin() + (userChoice - 1));   
            
        }

        void sellItem() { 
            if (inventory.empty() == true) {
                std::cout << "Nothing to sell." << '\n';
                return; 
            }

            int userChoice = 0; 
            viewInventory(); 
            std::cout << "Which item would you like to sell? " << '\n';
            std::cin >> userChoice; 
            
            while (std::cin.fail() || userChoice < 1 || userChoice > inventory.size()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n'); 
                std::cout << "Choose a valid item option." << '\n';
                std::cin >> userChoice;
            }

            std::cout << "Selling " << inventory[userChoice - 1].rarityToString() << " " << inventory[userChoice - 1].getName() << '\n';
            std::cout << "Value: " << inventory[userChoice - 1].getGold() << '\n';

            int value = inventory[userChoice - 1].getGold();  
            std::cout << "Sold " << inventory[userChoice - 1].rarityToString() << " " << inventory[userChoice - 1].getName() << " for " << value << " gold" << '\n';
            gold += value; 
            inventory.erase(inventory.begin() + (userChoice - 1));   
            std::cout << "Total gold: " << gold << '\n';

        }


};


void openInventory(Adventurer& hero) { 
    int userChoice = 0; 
    while (userChoice != 6) {
        std::cout << " === INVENTORY SYSTEM ===" << '\n';
        std::cout << "1. Find Item " << '\n';
        std::cout << "2. View Inventory " << '\n';
        std::cout << "3. Inspect Item " << '\n';
        std::cout << "4. Drop Item" << '\n';
        std::cout << "5. Sell Item " << '\n';
        std::cout << "6. Leave " << '\n';
        std::cin >> userChoice;

        while (std::cin.fail() || userChoice < 1 || userChoice > 6) {
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
                hero.dropItem(); 
                break;
            case 5: 
                hero.sellItem();
                break;
            case 6:
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
