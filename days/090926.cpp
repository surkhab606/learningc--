#include <iostream>

int secretCode = 7; 

void openDungeonDoor(int code) {
    int numOfAttempts = 3; 
    int userGuess; 
    std::cout << "====DUNGEON DOOR====" << '\n'; 
    std::cout << "Enter the secret code (a random number from 1-10)... you have 3 attempts or else... " << '\n'; 
    std::cin >> userGuess;

    while (std::cin.fail()) { 
        std::cin.clear(); 
        std::cin.ignore(10000, '\n'); 
        std::cout << "Enter a number. Not a word. Idiot." << '\n';
        std::cin >> userGuess;
    }

    
    
    while (userGuess != secretCode && numOfAttempts > 1) {
        while (userGuess < 1 || userGuess > 10) {
            std::cout << "1-10. Idiot." << '\n';
            std::cin >> userGuess;
        }

        numOfAttempts -= 1;
        if (userGuess > secretCode) { 
            std::cout << "Too high. You have " << numOfAttempts << " attempts remaining." << '\n';
            std::cout << "Try again: " << '\n';
            std::cin >> userGuess;
        }         

        else {
            std::cout << "Too low. You have " << numOfAttempts << " attempts remaining." << '\n';
            std::cout << "Try again: " << '\n';
            std::cin >> userGuess;
        }

    }

    if (userGuess == secretCode) {
        std::cout << "Correct. But do you really want to be here?" << '\n';
    }

    else {
        std::cout << "No more attempts. Death with you." << '\n'; 
    }
}

int main() { 
    openDungeonDoor(secretCode); 
    return 0; 
    
}
