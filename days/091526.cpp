#include <iostream> 
void ogreTurn(int& playerHP, int& ogreHP) { 
    std::cout << "The ogre retaliated! The ogre dealt 14 damage to the Player!" << '\n';
        playerHP -= 14;
        if (playerHP <= 0) {
            playerHP = 0; 
            return; 
        }
}

void quickAttack(int& playerHP, int& ogreHP) {
    std::cout << "Player dealt 20 damage!" << '\n'; 
    ogreHP -= 20; 
    if (ogreHP <= 0) {
        ogreHP = 0;  
        return; 
    }

    else {
        ogreTurn(playerHP, ogreHP);
    }
}
    


void powerAttack(int& playerHP, int& ogreHP) {
    std::cout << "Player swung to hit for 35 damage... but hurt themselves (-10 HP) in the process..." << '\n'; 
    playerHP -= 10;
    if (playerHP <= 0) {
            playerHP = 0;
            return;
        }
    else {
        ogreHP -= 35; 
        if (ogreHP <= 0) {
            ogreHP = 0; 
            return; 
        }

        else {
            ogreTurn(playerHP, ogreHP);
        }
    }

}

void drinkPotion(int& playerHP, int& potionCount, int& ogreHP) {
    if (potionCount > 0) {
        std::cout << "Drank one potion." << '\n'; 
        potionCount -= 1; 
        playerHP += 30; 
        if (playerHP > 100) {
            playerHP = 100; 
        }

        ogreTurn(playerHP, ogreHP);
    }

    else { 
        std::cout << "You have no potions." << '\n';
    }
}

void inspectBattle(int playerHP, int potionCount, int ogreHP) { 
    std::cout << "Player HP: " << playerHP << " / 100 " << '\n'; 
    std::cout << "Potion count: " << potionCount <<'\n'; 
    std::cout << "Ogre HP: " << ogreHP << '\n'; 
}

void deathCheck(int& playerHP, int& ogreHP) { 
    if (playerHP == 0) {
        std::cout << "You were killed..." << '\n';
    }

    else if (ogreHP == 0) { 
        std::cout << "The ogre was defeated..." << '\n';
    }

    else {
        return; 
    }
    
}
void enterBridge(int playerHP, int potionCount, int ogreHP) {
    int userChoice = 0; 
    while(userChoice != 5 && playerHP > 0 && ogreHP > 0) { 
        std::cout << " ==== OGRE BRIDGE ==== " << '\n'; 
        std::cout << "1. Quick Attack " << '\n';
        std::cout << "2. Power Attack " << '\n';
        std::cout << "3. Drink Potion " << '\n';
        std::cout << "4. Inspect Battle " << '\n';
        std::cout << "5. Escape " << '\n';
        std::cin >> userChoice;
        
        while(std::cin.fail() || userChoice < 1 || userChoice > 5) { 
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            std::cout << "Please enter a valid menu option." << '\n'; 
            std::cin >> userChoice;
        }

        switch(userChoice) { 
            case 1:
                quickAttack(playerHP, ogreHP);
                break;
            case 2:
                powerAttack(playerHP, ogreHP);
                break;
            case 3:
                drinkPotion(playerHP, potionCount, ogreHP); 
                break;
            case 4:
                inspectBattle(playerHP, potionCount, ogreHP); 
                break;
            case 5:
                std::cout << "You barely got away..." << '\n';
                break; 
        }
    }
    if (playerHP == 0) {
        std::cout << "You were defeated..." << '\n';
    }

    if (ogreHP == 0) {
        std::cout << "The ogre was defeated..." << '\n';
    }

}

int main() { 
    enterBridge(75, 2, 80); 

    return 0; 
}
