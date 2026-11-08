#include <iostream>
#include <vector>


int main() {  
    int N = 0; 
    std::cin >> N; 
    int currentStreak = 1;
    int biggestStreak = 1; 
    int left = 0;
    int right = 1; 
    std::vector<int> nums (N, 0); // sets to size N initally and fills with 0s

    for (int i = 0; i < N; i++) {
        int currentNum = 0;
        std::cin >> currentNum;
        nums[i] = currentNum;  
    }

    while (right < N) { 
        if (nums[left] == nums[right]) { 
            currentStreak += 1;
            if (currentStreak > biggestStreak) {
                biggestStreak = currentStreak;
            }
            right += 1;
        }

        else {
            currentStreak = 1;
            left = right;
            right += 1;
        }
    }
    
    std::cout << biggestStreak << '\n';
    return 0;

}
