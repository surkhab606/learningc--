#include <iostream> 

int buyHealthPotion(int gold) {
    std::cout << "Buying health potion..." << '\n';
    if(gold >= 4) {
        std::cout << "Purchased health potion." << '\n';
        gold -= 4;
    }

    else { 
        std::cout << "Not enough gold. You can't afford this..." << '\n';
    }
    
    return gold; 
}

int buyTorch(int gold) {
    std::cout << "Buying torch..." << '\n';
    if(gold >= 3) {
        std::cout << "Purchased torch." << '\n';
        gold -= 3;
    }

    else { 
        std::cout << "Not enough gold. You can't afford this..." << '\n';
    }
    
    return gold; 
}

int buyIronKey(int gold) {
    std::cout << "Buying Iron Key..." << '\n';
    if(gold >= 7) {
        std::cout << "Purchased the Iron Key." << '\n';
        gold -= 7;
    }

    else { 
        std::cout << "Not enough gold. You can't afford this..." << '\n';
    }
    
    return gold; 
}

void checkGold(int gold) {
    std::cout << "You currently have " << gold << " gold." << '\n';

}


void enterShop(int gold) { 
    int userChoice; 
    

    while (userChoice != 5) {
        std::cout << "====GOBLIN MERCHANT====" << '\n'; 
        std::cout << "1. Health Potion - 4 gold" << '\n'; 
        std::cout << "2. Torch - 3 gold" << '\n'; 
        std::cout << "3. Iron Key - 7 gold" << '\n'; 
        std::cout << "4. Check Gold" << '\n'; 
        std::cout << "5. Leave Shop" << '\n'; 
        std::cin >> userChoice;

        while (std::cin.fail() || userChoice < 1 || userChoice > 5) {
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a valid menu option." << '\n';
            std::cin >> userChoice;
        }

        switch(userChoice) {
            case 1: 
                gold = buyHealthPotion(gold); 
                break;
            case 2: 
                gold =buyTorch(gold); 
                break;
            case 3:
                gold = buyIronKey(gold); 
                break;
            case 4:
                checkGold(gold); 
                break;   
        }
    }

    std::cout << "Goodbye!" << '\n'; 

}

int main() {
    enterShop(20); 
    return 0; 
    
}
