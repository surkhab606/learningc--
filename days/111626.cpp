#include <iostream>
#include <string>


int main() {
    std::string forceUserName = ""; 
    std::getline(std::cin, forceUserName);
    
    int a = 0; 
    std::cin >> a;

    int b = 0; 
    std::cin >> b; 

    int aminusb = 0; 
    std::cin >> aminusb;

    if (a > b) {
        std::cout << "VEIT EKKI"; 
    }

    else if (a - b == aminusb) {
        std::cout << "JEDI";
    }

    else if (a - b != aminusb) {
        std::cout << "SITH";
    }



    
    return 0; 
}
