#include <iostream>
#include <vector>

int main() {

    int n = 0; 
    std::cin >> n;
    int t = 0; 
    std::cin >> t; 
    std::vector<int> nums (n, 0); 
    int left = 0; 
    int right = 1; 



    for (int i = 0; i < n; i++) {
        int currentNum = 0;
        std::cin >> currentNum;
        nums[i] = currentNum;
    }

    bool outputNo = true; 
    while (left != n - 1) {
        if (nums[left] + nums[right] == t) {
            std::cout << "YES";
            outputNo = false; 
            break;
        } 

        else if (right == n - 1) { 
            left += 1; 
            right = left + 1;
        }
        
        else {
            right += 1;
        }
    }

    if (outputNo) {
        std::cout << "NO"; 
    }
    
    
    return 0;
}
