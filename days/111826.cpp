#include <iostream>
#include <string>

int main() {
    std::string result = ""; 
    
    for (int i = 0; i < 5; i++) {
        int currentNum = 0; 
        std::cin >> currentNum; 
        result += std::to_string(currentNum); 
    }
    
    while (result != "12345") {
        if (result[0] > result[1]) {
            char temp = result[0];
            result[0] = result[1]; 
            result[1] = temp; 
            for (char word : result) { 
                std::cout << word << " "; 
            }
        }
        
        if (result[1] > result[2]) {
            char temp = result[1];
            result[1] = result[2]; 
            result[2] = temp; 
            for (char word : result) { 
                std::cout << word << " "; 
            }
        }
        
        if (result[2] > result[3]) {
            char temp = result[2];
            result[2] = result[3]; 
            result[3] = temp;
            for (char word : result) { 
                std::cout << word << " "; 
            }
        }
        
        if (result[3] > result[4]) {
            char temp = result[3];
            result[3] = result[4]; 
            result[4] = temp;
            for (char word : result) { 
                std::cout << word << " "; 
            }
        }
        
    }
    
    
    
    return 0; 
    
}
