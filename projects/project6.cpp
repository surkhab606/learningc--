// SEP. 11 2026

#include <iostream> 

int purchaseItem(int value, int gold) {
    if (gold >= value) {
        gold -= value; 
        return gold;
    }
    else {
        return -99;
    }
}

void viewInventory(int potions, int torches, int keys) {
    std::cout << " === INVENTORY === " << '\n'; 
    std::cout << "You have " << potions << " potions." << '\n';
    std::cout << "You have " << torches << " torches." << '\n';
    std::cout << "You have " << keys << " keys." << '\n';
}

void viewGold(int gold) {
    std::cout << " === GOLD === " << '\n';
    std::cout << "You have " << gold << " gold." << '\n';
}

void enterEquipmentShop(int gold, int potions, int torches, int keys) {
    int userChoice = 0; 

    while(userChoice != 6) {
        std::cout << '\n'; 
        std::cout << " === ADVENTURER SHOP === " << '\n';
        std::cout << "1. Buy Health Potion - 4 gold " << '\n';
        std::cout << "2. Buy Torch - 3 gold " << '\n';
        std::cout << "3. Buy Iron Key - 7 gold " << '\n';
        std::cout << "4. View Inventory " << '\n';
        std::cout << "5. View Gold " << '\n';
        std::cout << "6. Leave " << '\n';
        std::cin >> userChoice; 

        while (std::cin.fail() || userChoice < 1 || userChoice > 6) {
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            std::cout << "Please enter a valid menu option." << '\n';
            std::cin >> userChoice;
        }

        switch(userChoice) { 
            case 1: 
                std::cout << "Purchasing Health Potion..." << '\n';
                if (purchaseItem(4, gold) != -99) {
                    gold = purchaseItem(4, gold);
                    std::cout << "Purchased Health Potion." << '\n';
                    potions += 1;
                } 

                else {
                    std::cout << "Not enough gold." << '\n';
                }

                break;
            case 2:
                std::cout << "Purchasing Torch..." << '\n';
                if (purchaseItem(3, gold) != -99) {
                    gold = purchaseItem(3, gold);
                    std::cout << "Purchased Torch." << '\n';
                    torches += 1;
                } 

                else {
                    std::cout << "Not enough gold." << '\n';
                }

                break; 
            case 3:
                std::cout << "Purchasing Iron Key..." << '\n';
                if (purchaseItem(7, gold) != -99) {
                    gold = purchaseItem(7, gold);
                    std::cout << "Purchased Iron Key." << '\n';
                    keys += 1;
                } 

                else {
                    std::cout << "Not enough gold." << '\n';
                }

                break;
            case 4: 
                viewInventory(potions, torches, keys); 
                break;
            case 5:
                viewGold(gold); 
                break;

        }
    }
    std::cout << "Goodbye!" << '\n'; 


}

int main() { 
    enterEquipmentShop(30, 0, 0, 0); 
    return 0; 
}
