#include <iostream>

int main() { 
    
    int n = 0;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        float long1 = 0.0; 
        std::cin >> long1; 
        float lat1 = 0.0; 
        std::cin >> lat1;
        
        if (long1 < -180.00 || long1 > 180.00 || lat1 < -90.0 || lat1 > 90.0 ) {
            std::cout << "INVALID" << '\n';
        }
        
        else {
            std::cout << "VALID" << '\n'; 
        }
    }
    
    
    
    
    
    
    return 0; 
}
