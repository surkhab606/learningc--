#include <iostream>

int main() {
    int firstNum; 
    std::cout << "Enter positive integer: " << '\n'; 
    std::cin >> firstNum; 

    int secondNum;
    std::cout << "Enter a second positive integer: " << '\n';
    std::cin >> secondNum; 

    int accumulator = 0; 

    while (firstNum >= 1) { 
        if (firstNum % 2 != 0) {
            accumulator += secondNum; 
        }

        
        int temp = firstNum / 2;
        firstNum = temp; 
            


        secondNum *= 2; 
    }

    std::cout << accumulator;
}
