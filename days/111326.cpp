#include <iostream>
#include <string>


int main() { 
    
    std::string var = "";
    
    while (var != "#") {
        std::cin >> var;
        int num = 0;
        std::string result = ""; 

        for (int i = 0; i < var.size() - 1; i++) { 
            
            if (var[i] == '1') {
                num += 1;   
            }

            result += var[i];
        }

        if (var.back() == 'e') { 
            if (num % 2 == 0) {
                std::cout << result + "0" << '\n'; //need to figure out how to concatenate strings
            }
            else {
                std::cout << result + "1"<< '\n'; //need to figure out how to concatenate strings
            }
        }
            
        else if (var.back() == 'o') {
            if (num % 2 == 0) {
                std::cout << result + "1"<< '\n'; //need to figure out how to concatenate strings
            }
            else {
                std::cout << result + "0" << '\n'; //need to figure out how to concatenate strings
            }
        }
    }
        
     return 0; 
}


