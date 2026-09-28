#include <iostream>
#include <string> 
#include <vector>

class Adventurer { 

    private:
        std::string name;
        int gold; 
        std::vector<std::string> inventory;

    public: 
        Adventurer(std::string adventurerName, int adventurerGold, std::vector<std::string> adventurerInventory) : 
        name(adventurerName), gold(adventurerGold), inventory(adventurerInventory) {
            if (gold < 0) {
                gold = 0; 
                }
            }
            
            void findItem() { 
                std::string userItem; 
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
                        userItem = "Unreliable Torch";
                        std::cout << "You got..." << '\n';
                        std::cout << "A " << userItem << '\n';
                        break;
                    case 2:
                        userItem = "Mythical Ice Sword"; 
                        std::cout << "You got..." << '\n';
                        std::cout << "The " << userItem << '\n';
                        break;
                    case 3:
                        userItem = "Elixir of Life"; 
                        std::cout << "You got..." << '\n';
                        std::cout << "The " << userItem << '\n';
                        break; 
                    case 4:
                        userItem = "Broken Axe"; 
                        std::cout << "You got..." << '\n';
                        std::cout << "A " << userItem << '\n';
                        break; 
                    case 5:
                        userItem = "Shattered Chestplate"; 
                        std::cout << "You got..." << '\n';
                        std::cout << "A " << userItem << '\n';
                        break; 
                    case 6:
                        userItem = "Cup of Water"; 
                        std::cout << "You got..." << '\n';
                        std::cout << "A " << userItem << '\n';
                        break; 
                }

                inventory.push_back(userItem); 
            }

            void viewInventory() {
                if (inventory.empty() == true) {
                    std::cout << "Inventory is empty." << '\n';
                }

                else {
                    std::cout << " === INVENTORY === " << '\n';
                    for (int i = 0; i < inventory.size(); i++) {
                        std::cout << i + 1 << ".  " << inventory[i] << '\n';
                    }
                }
            }

            void viewItem() { 
                int userOption = 0; 
                viewInventory(); 
                std::cout << "Select an inventory item to inspect." << '\n';
                std::cin >> userOption; 

                while (std::cin.fail() || userOption < 1 || userOption > inventory.size()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n'); 
                    std::cout << "Please enter a valid inventory item number." << '\n';
                    std::cin >> userOption;
                }

                std::cout << "You selected: " << inventory[userOption - 1] << '\n';
            }

            void dropLastItem() {
                if (inventory.empty() == true) {
                    std::cout << "Nothing to drop." << '\n';
                }

                else {
                    std::cout << "You dropped " << inventory.back() << '\n';
                    inventory.pop_back(); 
                }
                
            }
            

        };

void openBackpack(Adventurer& hero) { 
    int userChoice = 0; 
    while (userChoice != 5) {
        std::cout << " === ADVENTURER BACKPACK === " << '\n';
        std::cout << "1. Find Item" << '\n';
        std::cout << "2. View Inventory" << '\n';
        std::cout << "3. View Item" << '\n';
        std::cout << "4. Drop Last Item" << '\n';
        std::cout << "5. Leave" << '\n';
        std::cin >> userChoice; 

        while (std::cin.fail() || userChoice < 1 || userChoice > 5) {
            std::cin.clear();
            std::cin.ignore(10000, '\n'); 
            std::cout << "Please enter a valid menu option." << '\n';
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
                hero.viewItem();
                break;
            case 4:
                hero.dropLastItem();
                break;
            case 5:
                break;
        }

    }

    std::cout << "Goodbye!" << '\n';
}


int main() { 
    Adventurer adventurer ("Jake", 0, {});
    openBackpack(adventurer); 
    return 0;
}
