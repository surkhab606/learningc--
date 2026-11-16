#include <iostream>
#include <map> 


int main() {
    int n = 0; 
    std::cin >> n;

    std::map<int, int> numberMap{{}}; 

    for (int i = 0; i < n; i++) {
        int userRoll = 0;
        std::cin >> userRoll; 
        
        if (numberMap.contains(userRoll)) {
            numberMap[userRoll] += 1;
        }

        else {
            numberMap[userRoll] = 1;
        }
    }

    


    
    return 0; 
}
