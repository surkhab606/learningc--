#include <iostream>
#include <string>
#include <vector>

int main() {
    int n; 
    std::cin >> n; 

    std::vector<std::string> absentees;
    std::string pending = ""; 

    for (int i = 0; i < n; i++) {
        std::cin >> pending;

        if (pending == "Present!") {
            pending == ""; 
        }
        
        else {
            absentees.push_back(pending); 
            std::cin >> pending;
        }



    }

    if (pending != "") { 
        absentees.push_back(pending); 
    }
    return 0; 
}
